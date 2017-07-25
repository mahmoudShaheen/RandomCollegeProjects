// lab

#include <iostream>
#include <time.h>
using namespace std;

char seqA[] = "DJQERYWGBRKNZIGDMMYAHDFZMIGRSHMDYQFFHQSPGKCQKKGMPGPSJRNMRPUSFGVAEVQDSOPAXOBDYLSCBEQVULMNJZYMHYICNDCNLKHRUHWRTBJZDDDJKEIUPQARCIHZAAOGECCQLYPLBTILTCQAQRMJJQCPXGXFOLUSTWAIGJPABRZVCDCAWZBZBLDYOBULWFSZJEIRLWTPWZTLGGOKIJNJZZLRQJMYWVBPYCOMCWPZYHCGMXGTEKKLQEQEGSLHWOJEPWIAQEENXCQKCXJMWXATIFLVPFWNHIAKUXHYCSGOVWLFXRDFFSCFQMTTLSRIFIWFSTATCRJRTUTDTOIKRKPHRLAWUUVQRHGANNADETFKIZKTMEPTSAUDIMTGPWGONWZCGZLIUXMGEFFKLMNUKPAWUNGWWEHZRZNJYEEDSBGMXLUEYPKWNRLOXMAPTUNYEVLWFNVNCJKTLBHROFYXKBFVBWCYYAFPGLXBWGMEMBJAZAOEVJHMKVZZLTBRXRQEVUMUHEHJDHMUPKRMRDIUTQOLNEBHCPNSZWRPPABJYQVDKOKONGDFWXYLAFSOINCYQNWZPUEPDMRZDOVUTFUHWOANPDMBJFCYPWNGFZXVUOPFKVYUQOSOTJLFLDFCHZBJLEBACQMGPTNCIWRVFQAEEWVBUZGKCUWEYVNGVMXLVAHWJLFVARDDBTKETHECNGFCBMJDRBJLTOGVRXZFIOAGYGULPDYFHCFNWKDGCYVMSGXVKKTETCCODANFZZTEKMR";
char seqB[] = "DFFVHIQXDASCAWJYYYOKNDZGSYYWNCQKRHRFFEBRHPGSSSMSBOAQLGEQQHXZTIAUGLVRXMTFJFTUUKFPDQERMXTXDGAJMJJFYIVKWQYNRDXBRECNJIUAJWAMACLKPYMASFWYQKVLBEJMJTVWKPOZHCYGRUXTHTQKSNDZAGLQDMLGZRXKAPNIVPNMPVTYEOZOFSDNOHMRIROYJOLFXHHFESNIYJKPCKOBNSKGHFTRFNYNKMFTIJFAUHDXFGQKEVJTZLWTOOESCSDTUUUMBEIZVESLNVNIFPUHQVQONIOOSITJBLLPNLYRYMIIPPKITNKVTGVKXJBMJFFFGHUHTRGLFHXRRXZIXISSKHZQWIRUINHVUIHOUSDBBOOZIGDEHYIKLQZGUHJSASGDMQZJGCGMNPFBUCJYTLVBVWQASCEKHRDTJPNJQCSHFDBCOZYYGILPZLNEHJYKUAJQFBBCRRPOWSALCPWPLFAJPFBUCMSOIOGWORBTPTWWZDMDJSDQJYGVMROZRZOPJNIPEGNZZBUZTNJPCVKEMHALQKSVYHJURSZULFUMVPXPOQTVQDTEGXFZDTVQLURIKTVGTJNXQYMSRCZYPTIHVWDPGVONZXQCXXDWRTDYBXTVQZFVVHVUIERBOADJCEIBMYXSATQJIPWGFNZGCZYDECIQPLBFCRDFTZSLAWRRTJGJBRDSODMJERVATVDXEMWUEAOY";
int arr[10000][10000];

int x;
int max(int x, int y){
	return x > y ? x : y;
}

void main()
{

	int n = strlen(seqA);
	int m = strlen(seqB);
	



	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			arr[i][j] = 0;
		}
	}



	clock_t tStart = clock();
	//#pragma omp parallel for
	int y ,c , id, j, jd;
	int ix = 1;
	/*
	int **arr = new int*[m+1];
	for (int c = 0; c < m+1; c++) {
		arr[c] = new int[n+1];
	}
	*/
	
	for ( ix = 1; ix < m + 1; ix++){
		id = 1;
		if ( ix > m )
			y = 1 + (ix - m);
		else
			y = 1;
#pragma omp parallel for num_threads(3) schedule(dynamic,1000)
		for (jd = ix; jd >= y; jd--){
			if (seqA[id - 1] == seqB[jd - 1])
			    arr[id][jd] = arr[id - 1][jd - 1] + 1;
			else
				arr[id][jd] = max(arr[id - 1][jd], arr[id][jd - 1]);
			id++;
		}
	}

	for (j = 2; j < n + 1; j++){
		jd = m;
#pragma omp parallel for num_threads(3) schedule(dynamic,1000)
		for (id = j; id < n + 1; id++){
			if (seqA[id - 1] == seqB[jd - 1])
				arr[id][jd] = arr[id - 1][jd - 1] + 1;
			else
				arr[id][jd] = max(arr[id - 1][jd], arr[id][jd - 1]);
			jd--;
		}
	}
	/*
	for (int i = 0; i < n+1; i++){
		for (int j = 0; j < m+1; j++){
			cout << " " << arr[i][j] << " ";
		}
		cout << endl;
	}
	*/
	/*
	for (int i = 0; i < sizeY; ++i) {
		delete[] ary[i];
	}
	delete[] ary;
	*/
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	system("pause");
}




/*

clear
clc
%code
seqA = char('anas');
seqB = char('anaxrrs');
n = length(seqA);
m = length(seqB);
arr = zeros(n+1,m+1);
y = 2;

for j = 2:(m+1)
id = 2;
if j > n+1
y = 2 + (j-(n+1));
else
y = 2;
end

for jd = j:-1:y %from j to y and decrement 1 in each iteration
if seqA(id-1) == seqB(jd-1)
arr(id,jd) = arr(id-1,jd-1) + 1;
else
arr(id,jd) = max( arr(id-1,jd) , arr(id,jd-1));
end
id = id+1;
end

end
%{
% the max id that could be reached
if n <= m
id = jd;
else
id = n+1;
end
%}

for i = 3:(n+1)
jd = (m+1);
for id = i:+1:(n+1)

if seqA(id-1) == seqB(jd-1)
arr(id,jd) = arr(id-1,jd-1) + 1;
else
arr(id,jd) = max( arr(id-1,jd) , arr(id,jd-1));
end
jd = jd-1;

end
end

disp(['LCS is ',num2str(arr(n+1,m+1))])

*/