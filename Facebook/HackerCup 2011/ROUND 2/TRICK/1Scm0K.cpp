#include <cstdio>

const int MAX = 1000000;
const int MOD = 1000000007;
int least[1000020];
bool valido[1000020];
char parity[1000020];
int N, A,B,C,D;

int pow(int base, int exp){
	if(exp==0)return 1;
	
	long long res = pow(base,exp/2);
	res = (res*res)%MOD;
	if(exp%2)res = (res*base)%MOD;
	
	return (int)res;
}

int get2(int ini, int fim, int common){
	if(ini%common != 0){
		ini -= ini%common;
		ini += common;
	}
	if(fim%common != 0){
		fim -= fim%common;
	}
	if(ini > fim)return 0;
	int poss = (fim - ini)/common + 1;
	return pow(poss, N);
}

int get(int common){
	int res = 0;
	res = get2(A,D,common);
	res = (res - get2(B+1,D,common))%MOD;
	res = (res - get2(A,C-1,common))%MOD;
	res = (res + get2(B+1,C-1,common))%MOD;
	return res;
}

int main(){
	
	int casos;
	
	scanf("%d", &casos);
	
	for(int i = 1; i <= MAX; i++)
		least[i] = i;
	
	for(int i = 2; i <= MAX; i++){
		if(least[i] == i){
		//	printf("%d primo\n", i);
			for(int j = 2*i; j <= MAX; j+= i){
				if(least[j] == j)
					least[j] = i;
			}
		}
		int j = i;
		bool repete = false;
		int conta = 0;
		while(j != 1){
			if(least[j] == least[j/least[j]]){
				repete = true;
			}
			conta ^= 1;
			j /= least[j];
		}
		if(!repete){
			valido[i] = true;
			parity[i] = conta;
		}else valido[i] = false;
	}
	int res;
	while(casos--){
		scanf("%d%d%d%d%d", &N, &A,&B,&C,&D);
		res = get(1);
		for(int i = 2; i <=	D; i++){
			if(!valido[i])continue;
			if(parity[i] == 1){
				res = (res - get(i))%MOD;
			}else{
				res = (res + get(i))%MOD;
			}
		}
		if(res < 0)
			res += MOD;
		printf("%d\n", res);
	}
	
	return 0;
}
