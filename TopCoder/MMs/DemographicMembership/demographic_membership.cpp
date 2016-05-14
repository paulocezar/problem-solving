#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

const int MAXK = 393;
const int KP = 13;
const int COMMITTEE_SIZE = 99;
const int FIELDS_PERCENTAGE = 73;

const long double sqrt2pi = sqrt(2.0 * M_PI);

const long double EPS = 1e-13;
inline int sgn(long double a) { return (a > EPS) ? 1 : ((a < -EPS) ? -1 : 0); }
inline int cmp(long double a, long double b) { return sgn(a - b); }

class Customer {
public:
  int id, demoX;
  vector<long double> fields;
  long double norm;
  bool got_norm = false;

  void integer_field(int val) {
    fields.push_back(val);
    norm += fields.back() * fields.back();
  }

  void real_field(long double val) {
    fields.push_back(val);
    norm += fields.back() * fields.back();
  }

  long double get_norm() {
    if (!got_norm) {
      got_norm = true;
      norm = sqrt(norm);
    }
    return norm;
  }

  long double similarity(Customer &c) {
    long double sim = 0.0;
    int fsz = fields.size();

    for (int i = 0; i < fsz; ++i) {
      sim += fields[i] * c.fields[i];
    }
    sim /= (get_norm() * c.get_norm());
    return sim;
  }
};

class DemographicMembership {
public:
  vector<int> predict(int testType, vector<string> trainingData, vector<string> testingData) {
    #ifdef OFFLINE_TEST
    auto t0 = chrono::high_resolution_clock::now();
    #endif
    int testing_size = testingData.size();
    vector<int> predictions(testing_size);

    int training_size = trainingData.size();
    int K = min(MAXK, (KP * training_size) / 100);
    vector<Customer> training_data(training_size);
    vector<long double> similarities(training_size);
    vector<int> ids(training_size);

    for (int i = 0; i < training_size; ++i) {
      training_data[i] = create_customer(trainingData[i]);
      ids[i] = i;
    }

    int fields_size = training_data[0].fields.size();
    vector<int> candidate_fields(fields_size);

    int fields_subset_size = (fields_size * FIELDS_PERCENTAGE) / 100;
    vector<int> fields_to_use(fields_subset_size);

    for (int i = 0; i < fields_size; ++i) {
      candidate_fields[i] = i;
    }

    for (int i = 0; i < testing_size; ++i) {
      Customer c = create_customer(testingData[i]);

      for (int j = 0; j < training_size; ++j) {
        similarities[j] = c.similarity(training_data[j]);
      }

      sort(ids.begin(), ids.end(), [&similarities](int a, int b) {
        return (cmp(similarities[a],similarities[b]) > 0); });

      vector<int> sampling_candidates;
      int sample_from_class[2] = {0, 0};
      vector<long double> priors = {0.0, 0.0};

      for (int j = 0; j < training_size; ++j) {
        if (sample_from_class[training_data[ids[j]].demoX] < K) {
          sampling_candidates.push_back(ids[j]);
          sample_from_class[training_data[ids[j]].demoX]++;
        }
        priors[training_data[ids[j]].demoX] += 1.0;
        if ((sample_from_class[0] >= K) && (sample_from_class[1] >= K)) break;
      }
      long double tot = priors[0] + priors[1];
      priors[0] /= tot;
      priors[1] /= tot;

      vector<int> sample(sampling_candidates.size());
      long double committee_likelihood[2] = {0.0, 0.0};

      long double majority[2] = {0.0, 0.0};

      for (int judge = 0; judge < COMMITTEE_SIZE; ++judge) {
        gen_sample(sampling_candidates, sample);

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        mt19937 eng(seed);
        uniform_int_distribution<int> unif(0, fields_size - 1);
        shuffle(candidate_fields.begin(), candidate_fields.end(), eng);
        int pos = unif(eng);
        for (int j = 0; j < fields_subset_size; ++j) {
          fields_to_use[j] = candidate_fields[pos];
          pos++;
          if (pos == fields_size) pos = 0;
        }

        sort(sample.begin(), sample.end());
        sort(fields_to_use.begin(), fields_to_use.end());

        auto rnb_result = get_rnb_result(training_data, sample, fields_to_use, priors, c);

        committee_likelihood[0] += rnb_result.first;
        committee_likelihood[1] += rnb_result.second;

        if (cmp(rnb_result.first, rnb_result.second) > 0) majority[0] += 1.0;
        else majority[1] += 1.0;
      }

      tot = committee_likelihood[0] + committee_likelihood[1];
      committee_likelihood[0] /= tot;
      committee_likelihood[1] /= tot;

      majority[0] /= COMMITTEE_SIZE;
      majority[1] /= COMMITTEE_SIZE;

      committee_likelihood[0] += 2 * majority[0];
      committee_likelihood[1] += majority[1];

      tot = committee_likelihood[0] + committee_likelihood[1];
      committee_likelihood[0] /= tot;
      committee_likelihood[1] /= tot;

      if (cmp(committee_likelihood[0], priors[1]) >= 0) predictions[i] = 0;
      else if (cmp(committee_likelihood[1], priors[0]) > 0) predictions[i] = 1;
      else if (cmp(priors[0], priors[1]) >= 0) predictions[i] = 0;
      else predictions[i] = 1;
    }

    #ifdef OFFLINE_TEST
    auto t1 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t1 - t0);
    cout << "Prediction time: " << fixed << setprecision(6) << time_span.count() << " seconds" << endl;
    #endif
    return predictions;
  }

private:
  pair<long double, long double> get_rnb_result(vector<Customer> &train, vector<int> &sample, vector<int> &fields_to_use, vector<long double> &priors, Customer &subject) {

    long double likelihood[2] = { log(priors[0]), log(priors[1]) };
    int fields_to_use_sz = fields_to_use.size();

    vector<vector<long double>> means(2, vector<long double>(fields_to_use_sz, 0.0));
    int cnt[2] = {0, 0};

    for (auto &id : sample) {
      Customer &train_subject = train[id];

      int pos = 0;
      for (auto &field : fields_to_use) {
        means[train_subject.demoX][pos] += train_subject.fields[field];
        //means[2][pos] += train_subject.fields[field];
        pos++;
      }
      cnt[train_subject.demoX]++;
      //cnt[2]++;
    }

    for (int clss = 0; clss < 2; ++clss) {
      if (!cnt[clss]) continue;
      for (auto &mean : means[clss]) {
        mean /= cnt[clss];
      }
    }

    vector<vector<long double>> devs(2, vector<long double>(fields_to_use_sz, 0.0));

    for (auto &id : sample) {
      Customer &train_subject = train[id];

      int pos = 0;
      for (auto &field : fields_to_use) {
        long double df = (train_subject.fields[field] - means[train_subject.demoX][pos]);
        df *= df;
        devs[train_subject.demoX][pos] += df;

        // df = (train_subject.fields[field] - means[2][pos]);
        // df *= df;
        // devs[2][pos] += df;
        pos++;
      }
    }

    for (int clss = 0; clss < 2; ++clss) {
      if (!cnt[clss]) continue;
      for (auto &dev : devs[clss]) {
        dev = sqrt(dev / cnt[clss]);
      }
    }

    for (int clss = 0; clss < 2; ++clss) {
      for (int pos = 0; pos < fields_to_use_sz; ++pos) {
        long double pxc = pdf(subject.fields[pos], means[clss][pos], devs[clss][pos]);
        if (sgn(pxc)) likelihood[clss] += log(pxc);
      }
    }
    long double ax = likelihood[0] + likelihood[1];
    return make_pair(likelihood[0]/ax, likelihood[1]/ax);
  }

  inline long double pdf(long double x, long double mu, long double sigma) {
    return exp(-1.0 * (x - mu) * (x - mu) / (2 * sigma * sigma)) / (sigma * sqrt2pi);
  }

  Customer create_customer(string &raw) {
    Customer c;
    stringstream in(raw);
    string field;
    int idx = 1;
    while (getline(in, field, ',')) {
      switch (idx) {
        case 1: //CONSUMER_ID
          c.id = stoi(field);
          break;
        case 2: // AGE
          if (field == "NA") field = "45";
          c.integer_field(stoi(field));
          break;
        case 3: // GENDER
          if (field == "M") c.integer_field(0);
          else if (field == "F") c.integer_field(2);
          else c.integer_field(1);
          break;
        case 4: // REGISTRATION_ROUTE
          c.integer_field(field[0]-'A');
          break;
        case 5: // REGISTRATION_CONTEXT
          if (isdigit(field[0])) c.integer_field(50 - (field[0]-'0'));
          else if (field == "NA") c.integer_field(26);
          else c.integer_field(field[0] - 'A');
          break;
        case 6: // REGISTRATION_DAYS
          if (field == "NA") field = "871";
          c.integer_field(stoi(field));
          break;
        case 7: // OPTIN
          if (field == "N") c.integer_field(0);
          else if (field == "Y") c.integer_field(2);
          else c.integer_field(1);
          break;
        case 8: // IS_DELETED
        case 10: // SOCIAL_AUTH_FACEBOOK
        case 11: // SOCIAL_AUTH_TWITTER
        case 12: // SOCIAL_AUTH_GOOGLE
          if (field == "N") c.integer_field(0);
          else c.integer_field(1);
          break;
        case 9: // MIGRATED_USER_TYPE
          if (field == "NA") field = "C";
          c.integer_field(field[0]-'A');
          break;
        case 233: // PLATFORM_CENTRE
          if (field == "NA") field = "2";
          c.integer_field(stoi(field));
          break;
        case 234: // TOD_CENTRE
          if (field == "NA") c.integer_field(3);
          else if (field[0] < '3') c.integer_field(stoi(field));
          else c.integer_field(stoi(field) + 1);
          break;
        case 235: // CONTENT_CENTRE
        case 236: // INTEREST_BEAUTY
        case 237: // INTEREST_TECHNOLOGY
        case 238: // INTEREST_FASHION
        case 239: // INTEREST_COOKING
        case 240: // INTEREST_HOME
        case 241: // INTEREST_QUALITY
        case 242: // INTEREST_DEALS
        case 243: // INTEREST_GREEN
          if (field == "0") c.integer_field(0);
          else if (field == "1") c.integer_field(2);
          else c.integer_field(1);
          break;
        case 244:
          c.demoX = stoi(field);
          break;
        default:
          if (idx <= 170) c.integer_field(stoi(field));
          else c.real_field(stold(field));
      }
      idx++;
    }
    return c;
  }

  void gen_sample(vector<int> &ids, vector<int> &resulting_sample) {
    int sample_size = ids.size();
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 eng(seed);
    uniform_int_distribution<int> unif(0, sample_size - 1);

    for (int i = 0; i < sample_size; ++i) {
      resulting_sample[i] = ids[unif(eng)];
    }
  }
};



#ifdef OFFLINE_TEST

vector<string> load_all_data(string csv_path) {
  vector<string> all_data;
  ifstream ifs(csv_path);
  string row;
  // skip header
  getline(ifs,row);
  while(getline(ifs,row)) {
    // remove carriage return
    if(row.back()=='\r') {
      row.pop_back();
    }
    all_data.push_back(row);
  }
  return all_data;
}

void training_testing_split(const vector<string>& all_data, vector<string>& training_data, vector<string>& testing_data, vector<string>& testing_truth) {
  training_data.clear();
  testing_data.clear();
  testing_truth.clear();

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  mt19937 eng(seed);
  uniform_int_distribution<> unif(0, 2);

  for (auto& row: all_data) {
    bool use_as_testing_data = (unif(eng) == 0);
    if (use_as_testing_data) {
      int pos = row.find_last_of(',');
      string left = row.substr(0, pos);
      string right = row.substr(pos+1, row.size() - (pos+1));
      testing_data.push_back(left);
      testing_truth.push_back(right);
    } else {
      training_data.push_back(row);
    }
  }
  return;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string csv_path = "demographic_membership_training.csv";
  vector<string> all_data = load_all_data(csv_path);

  // split data
  vector<string> training_data, testing_data, testing_truth;
  training_testing_split(all_data, training_data, testing_data, testing_truth);

  // DemographicMembership instance and predict function call
  int test_type = 0;
  DemographicMembership demoX;
  vector<int> prediction = demoX.predict(test_type, training_data, testing_data);

  // scoring
  vector<int> truth;
  for (string& s: testing_truth) {
    truth.push_back(stoi(s));
  }

  double dot = inner_product(prediction.begin(), prediction.end(), truth.begin(), 0);
  double precision = dot / accumulate(prediction.begin(), prediction.end(), 0);
  double recall = dot / accumulate(truth.begin(), truth.end(), 0);
  double score = 1e6 * min(precision, recall);
  cout << "Score: " << precision << ", " << recall << ", " << score << endl;

  return 0;
}

#endif
