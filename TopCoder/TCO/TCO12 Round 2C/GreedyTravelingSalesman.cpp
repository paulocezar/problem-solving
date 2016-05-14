// Paste me into the FileEdit configuration dialog

#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N, dist[33][33], all;
int fixed_u, fixed_v;

pair<int,int> cand[33];

int calc( int last, int used ){
	if( used == all ) return 0;
	
	int len = 0;
	REP( i, N ) if( !(used & (1<<i)) ){
		cand[len++] = MP( dist[last][i], i );
	}
	sort( cand, cand+len );
		
	if( last == fixed_u ){
		
		int oc = cand[0].first;
		int og = cand[0].second;
		int worst = 0;
		
		if( og == fixed_v ){
			
			int o1 = ( (len>1)?( max( oc, (cand[1].second>fixed_v)?(cand[1].first):(cand[1].first-1) ) ):(9999) );
			
			
			cand[0].first = 9999;
			sort( cand, cand+len );
			int o2 = cand[0].first;
			int h2 = cand[0].second;
			
			worst = max( o1+calc(fixed_v,used|(1<<fixed_v)), o2+calc(h2,used|(1<<h2)) );
			
		} else {
			
			int mn = 0;
			REP( pos, len ) if( cand[pos].second == fixed_v ){
				mn = cand[pos].first;
			}
			
			if( (mn == oc) && (mn > 1) ) worst = (mn-1) + calc(fixed_v,used|(1<<fixed_v));
			else if( (mn > oc) && (fixed_v < og) ) worst = oc + calc(fixed_v,used|(1<<fixed_v));
			else if( (mn > oc) && (oc > 1) ) worst = (oc-1) + calc(fixed_v,used|(1<<fixed_v));
		}
		
		worst = max( worst, oc+calc(og,used|(1<<og)) );
		return worst;	
	}
	
	return cand[0].first + calc( cand[0].second, used | (1<<cand[0].second) );

}


class GreedyTravelingSalesman {
public:
	int worstDistance( vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones ) {
		
		N = SIZE(thousands);
		REP( i, N ) REP( j, N ){
			dist[i][j] = 1000*(thousands[i][j]-'0') + 100*(hundreds[i][j]-'0') + 10*(tens[i][j]-'0') + (ones[i][j]-'0');
		}
		
		fixed_u = -1;
		fixed_v = -1;
		all = (1<<N)-1;
		
		int ans = calc(0,1);
		
		for( fixed_u = 0; fixed_u < N; fixed_u++ )
			for( fixed_v = 0; fixed_v < N; fixed_v++ ) if( fixed_u != fixed_v )
			ans = max( ans, calc(0,1) );	
			
		return ans;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string thousands[]        = {"055", "505", "550"};
			string hundreds[]         = {"000", "000", "000"};
			string tens[]             = {"000", "000", "000"};
			string ones[]             = {"000", "000", "000"};
			int expected__            = 14999;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string thousands[]        = {"018", "101", "990"};
			string hundreds[]         = {"000", "000", "990"};
			string tens[]             = {"000", "000", "990"};
			string ones[]             = {"000", "000", "990"};
			int expected__            = 17999;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string thousands[]        = {"00888", "00999", "00099", "00009", "00000"}
;
			string hundreds[]         = {"00000", "00999", "00099", "00009", "00000"}
;
			string tens[]             = {"00000", "10999", "11099", "11109", "11110"}
;
			string ones[]             = {"01000", "00999", "00099", "00009", "00000"}
;
			int expected__            = 37997;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string thousands[]        = {"000000", "000000", "990999", "999099", "999909", "999990"};
			string hundreds[]         = {"000000", "000000", "990999", "999099", "999909", "999990"};
			string tens[]             = {"000000", "000000", "990999", "999099", "999909", "999990"};
			string ones[]             = {"011111", "101111", "990998", "999099", "999809", "999980"};
			int expected__            = 39994;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string thousands[]        = {"00", "00"};
			string hundreds[]         = {"00", "00"};
			string tens[]             = {"00", "00"};
			string ones[]             = {"01", "10"};
			int expected__            = 9999;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string thousands[]        = {"0930", "1064", "0104", "1070"};
			string hundreds[]         = {"0523", "1062", "6305", "0810"};
			string tens[]             = {"0913", "0087", "3109", "1500"};
			string ones[]             = {"0988", "2030", "6103", "5530"};
			int expected__            = 14124;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string thousands[]        = {"0329", "2036", "2502", "8970"};
			string hundreds[]         = {"0860", "5007", "0404", "2770"};
			string tens[]             = {"0111", "2087", "2009", "2670"};
			string ones[]             = {"0644", "1094", "7703", "7550"};
			int expected__            = 17785;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			string thousands[]        = {"098444156277392825243100607342", "200097656837707947798866622385",
"290231695687128834848596019656", "407026565077650435591867333275",
"843401002617957470339040852874", "349970591997218853400632158696",
"419933000593511123878416328483", "696294503254214847884399055978",
"641473980706392541888675375279", "936720077098054565078142449625",
"203476089500970673371115103717", "511071853860312304204656816567",
"347105714685052402147763392257", "125122220860203856679947732062",
"121462979669220132944063071653", "928254504048223043681383050365",
"502607124708785202536036594373", "793596587517012870906900400361",
"712360060935346182084840996318", "761671392040312345002273366240",
"812935320276738878200716148806", "228506917464479046839069740872",
"755395721473881083093906155745", "192597782177910118061710039501",
"721382839206745793530453013267", "076061794267810491768114700256",
"857528357758085424372388710251", "173322450800442594145600093043",
"761667192345925280210514410800", "521229810525064090301842864060"};
			string hundreds[]         = {"098270581534726237580246464451", "108829763716747148395013332067",
"830061279541380758964430491222", "431005058477371114834129826284",
"601807314489142917339949914290", "330640126699733151822328009407",
"851821069798846354566780680271", "648888407535627630663351884365",
"051398660825518466890170447894", "631934884097214069747147155777",
"768071219404930950472885304916", "924954163330715847561718395488",
"189910033179029204426829479070", "960645776060701332402794474433",
"244875842263950931884758650019", "528470075229660077692189442311",
"752198673046476808978058423064", "899325998610605600525587569431",
"965750123741820904031880230236", "121658852172052167706008445728",
"556199378085507717770434101126", "864838242791403197110088834005",
"593435343245223500439707230479", "622529771475840345624500421425",
"503486612623475041392122088159", "518334626169655694269507400008",
"967091631529233593414345370288", "300474162107271438029222620086",
"010527691044447729596127150108", "742822904991333205419603623270"};
			string tens[]             = {"029421809872798033258029765788", "705135039569772524273274786652",
"170567418260893393020344098265", "401043354947659563658581268242",
"746709065616595245635350557925", "739570024549618413776557843034",
"184597012262496958610853505745", "689811400727818703807051112784", 
"894453010121164288965541305235", "323145029073008946088869964941", 
"834269564400729646453274750586", "538976762970745472202055589093", 
"765511399939087047106252621388", "906733295711605356366138410423", 
"107653940551700559321642810836", "428402693021051075533830345295", 
"386782660475155103347385287948", "936626025836194580089064628716", 
"718522629491464055045890912121", "370656945845300237607868352243", 
"951908186614186444840337711498", "535178875249889835014025850038", 
"505970047705717604298603983975", "484398304612602344941130624527", 
"048342694079170795987835013947", "860331019262176299872846206272", 
"549663926438975145562538360932", "329735455392841851511474791078", 
"711755200061373546828858448100", "778808866574640894148527759780"};
			string ones[]             = {"050738147930236727719964251439", "804492562859282318664226330103", 
"610197568193830684654773608216", "279000416545607314567843085541", 
"782201171759873927350740022455", "043370803444176631019883186675", 
"566092086050401228622782761449", "469598907881602996036692882305", 
"116923500417992303845370254124", "796876115092839169954790509461", 
"783836410405270687557924090071", "095144151150833738671751747749", 
"354474585664039135189964700948", "328968176148004939648962631420", 
"829651915384290848347221555092", "170980383407813034573738951375", 
"728655435703349509419725538350", "121896684176286430427852435647", 
"315710894574884960021671476788", "592177839598531202003634382961", 
"876587919610157913350259498196", "505517243779897451333006271744", 
"618607877753891664471800511372", "826358757330233811836040764274", 
"206641252044293046424432092833", "704519364781672964993499009545", 
"624793571592392775564426440338", "571938479010503551295729304078", 
"077967252884369103891335711508", "870185204806328841827105139840"};
			int expected__            = 39896;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string thousands[]        = ;
			string hundreds[]         = ;
			string tens[]             = ;
			string ones[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string thousands[]        = ;
			string hundreds[]         = ;
			string tens[]             = ;
			string ones[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string thousands[]        = ;
			string hundreds[]         = ;
			string tens[]             = ;
			string ones[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GreedyTravelingSalesman().worstDistance(vector <string>(thousands, thousands + (sizeof thousands / sizeof thousands[0])), vector <string>(hundreds, hundreds + (sizeof hundreds / sizeof hundreds[0])), vector <string>(tens, tens + (sizeof tens / sizeof tens[0])), vector <string>(ones, ones + (sizeof ones / sizeof ones[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
