#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long l;
typedef long long ll;
typedef float f;
typedef double d;
typedef long double ld;
typedef double d;
#define nop cout << "no";
#define yup cout << "yes";
#define fine cout <<"OK\n";
#define c(x)  cout <<x
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define V2D(c,r) vector<vector <int>> VECT(c,vector<int>(r));
#define KHOD_HAT(FILE,FILE2) freopen(FILE,"r",stdin); freopen(FILE2,"w",stdout); auto start = high_resolution_clock::now();
#define KHOD(FILE) freopen(FILE,"r",stdin);
#define untie ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mem(x,n) memset(x,n,sizeof x);
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define allR(x) x.rbegin(),x.rend()
#define take(x) for (auto &it:(x))cin >> it;
#define print(x) for (auto &it:(x))cout << it << " ";
#define print2D(x) for (vector<int> vect1D : vect) {for (auto &it:vect1D)cout << it << " "; cout << endl;}
#define f0(n)  for (int i = 0; i < n; i++)
#define f1(n)  for (int i = 1; i <= n; i++)
#define isVOWEL(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
#define setP(n) cout << fixed<<setprecision(n);
const double pi=3.14159265359; //atan(1)*4 as precision(13)
const double e = 2.71828182846;
const int mod = 1e9+7;
#define countTime auto stop = high_resolution_clock::now(); auto duration = duration_cast<milliseconds>(stop - start); cout << "\n$time in ms: "<<duration.count();
int searchregex(string str, regex reg) {

    sregex_iterator first(str.begin(), str.end(), reg);
    sregex_iterator end;

    while (true) {
        if (first != end)
            return 1;
        else
            return 0;
        first++;
    }
}
class minheap {
    int* arr;
    int size;
    int elements;

    minheap(int sz) {
        size = sz;
        elements = 0;
        arr = new int(sz);
    }
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return (2 * i + 2); }
    bool isFull() { return elements == size; }

    void minheapifydown(int i) {
        int sindex = i;
        if (left(i) < elements && arr[left(i)] < arr[i])
            sindex = left(i);
        if (right(i) < elements && arr[right(i)] < arr[i])
            sindex = right(i);
        if (sindex != i) {
            swap(arr[i], arr[sindex]);
            minheapifydown(sindex);
        }
    }
    void insertkey(int value) {
        if (isFull())
            return;

        elements++;
        int i = elements - 1;
        arr[i] = value;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    void decreaseelement(int i, int value) {
        arr[i] = value;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    int deletemin() {
        if (elements <= 0)
            return -1;
        int min = arr[0];
        if (elements == 1) {
            elements--;
            return min;
        }
        arr[0] = arr[elements - 1];
        elements--;
        minheapifydown(0);
        return min;
    }
    void deletekey(int index) {
        decreaseelement(index, INT_MIN);
        deletemin();
    }
};
//.........................
int construct_segmant_tree_util(int arr[], int* st, int ss, int se, int si);
int* segmant_tree(int arr[], int n);
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return ((i * 2) + 1); }
int right(int i) { return ((i * 2) + 2); }
ll getmid(ll s, ll e) { return s + (e - s) / 2; }
int getMid(int s, int e) { return s + (e - s) / 2; }
int getmin(int a, int b) { return (a < b) ? a : b; }
int QMR_util(int* st, int ss, int se, int si, int qs, int qe);
int QMR(int* st, int n, int qs, int qe);
int construct_segmant_tree_util(int arr[], int* st, int ss, int se, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    int l = construct_segmant_tree_util(arr, st, ss, mid, left(si));
    int r = construct_segmant_tree_util(arr, st, mid + 1, se, right(si));
    st[si] = getmin(l, r);
    return st[si];

}
int* segmant_tree(int arr[], int n) {
    int h = (int)ceil(log2(n));
    int max_size = (int)(pow(2, h + 1) - 1);
    int* st = new int[max_size];
    construct_segmant_tree_util(arr, st, 0, n - 1, 0);
    return st;
}
int QMR_util(int* st, int ss, int se, int si, int qs, int qe) {
    //case 1 : out of range return nothing or max value
    if (ss > qe || se < qs)
        return INT_MAX;

    //case 2 in range we return the value to parent
    if (ss >= qs && se <= qe)
        return st[si];

    //case 3 partially included in range 
    int mid = getMid(ss, se);
    int l = QMR_util(st, ss, mid, left(si), qs, qe);
    int r = QMR_util(st, mid + 1, se, right(si), qs, qe);
    return getmin(l, r);

}
int QMR(int* st, int n, int qs, int qe) {
    if (qs <0 || qe > n - 1 || qs > qe)
        return -1;

    return QMR_util(st, 0, n - 1, 0, qs, qe);
}
//....................................................
struct comparestring {
    inline bool operator() (string& str1, string& str2) {
        // if (toupper(str1[0]) == 'A' )
        return str1.size() < str2.size();
    }
};  // struct to sort by length and the priority for the first one
vector<l>sorted_indeces(l arr[], l s) {

    vector<l>indeces(s);
    iota(indeces.begin(), indeces.end(), 0);

    stable_sort(indeces.begin(), indeces.end(),
        [&arr](l a, l b) { return arr[a] > arr[b]; });

    return indeces;
}
int isPalindrome2(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;

    // Reverse the string P
    reverse(P.begin(), P.end());

    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return 1;
    }
    // Otherwise
    else {
        // return "No"
        return 0;
    }
}
bool isPalindrome(string s) {
    int n = sz(s);
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}
//...............................................
const int sz = 10;
int arr[sz] = { 1,1,2,2,4,4,5,5,6,7 };
int iterative_bs(int value) {
    if (value > arr[sz - 1]) return -1;
    int s = 0, e = sz - 1;
    int mid;
    while (s < e) {
        mid = getMid(s, e);
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int iterative_lowerbound(int val) {
    if (val > arr[sz - 1]) return -1;
    int s = 0, e = sz - 1;
    int mid;
    while (s < e) {
        mid = getmid(s, e);
        if (arr[mid] < val) s = mid + 1;
        else e = mid;
    }
    return s;
}
int iterative_upperbound(int val) {
    if (val >= arr[sz - 1]) return -1;
    int s = 0, e = sz - 1;
    int mid;
    while (s < e) {
        mid = getmid(s, e);
        if (arr[mid] <= val) s = mid + 1;
        else e = mid;
    }
    return s;
}
//..........................................................
int utility_bs(vector <int>& arr, int s, int e, int value) {
    if (e >= s) {
        int mid = getmid(s, e);
        //base case
        if (arr[mid] == value) return mid;
        else if (arr[mid] > value) return utility_bs(arr, s, mid - 1, value);
        else  return utility_bs(arr, mid + 1, e, value);
    }
    return -1;
}
int  bs(int value) {
    vector <int >arr = { 1,1,2,2,4,4,5,5,6,7 };
    if (value > arr.back() || value < arr.front()) return -1;
    return utility_bs(arr, 0, arr.size() - 1, value);
}
int utility_lowerbound(vector <int>& arr, int s, int e, int val) {
    // Base Case
    if (s > e) return s;
    int  mid = getmid(s, e);
    if (arr[mid] < val) return utility_lowerbound(arr, mid + 1, e, val);
    else   return utility_lowerbound(arr, s, mid - 1, val);
}
int lowerbound(int val) {
    vector <int >arr = { 1,1,2,2,4,4,5,5,6,7 };
    if (val > arr.back()) return -1;
    return utility_lowerbound(arr, 0, arr.size() - 1, val);
}
int utility_upperbound(vector <int>& arr, int s, int e, int val) {
    // Base Case
    if (s > e) return s;
    int  mid = getmid(s, e);
    if (arr[mid] <= val) return utility_upperbound(arr, mid + 1, e, val);
    else return  utility_upperbound(arr, s, mid - 1, val);
}
int upperbound(int val) {
    vector <int >arr = { 1,1,2,2,4,4,5,5,6,7 };
    if (val >= arr.back())
        return -1;
    return utility_upperbound(arr, 0, arr.size() - 1, val);
}

vector <l>res(vector <l>a,l k,l m) {
    sort(a.begin(),a.end()); //n log(n)
    l s = 0;
    l e = k;
    l sum;
    l mid;
    while (s <= e) {
        mid = s + (e - s)/2;
        //cout << mid << " ";
        sum = 0;
        for (int i = 0; i <= mid; i++)  sum += (a[i] + (i * mid)); //became n log(n)
        //cout << sum<<" ";
        if (sum == m) return { mid,sum };
         if (sum < m)
            s = mid+1;
        else
            e = mid - 1;
    }
    if (sum > m) return{ 0,0 };
    return { mid,sum };
}

l fact(l n) {return (n == 1 || n == 0) ? 1 : n * fact(n - 1);}

ll powerrecursion(ll base, ll pwr) {

    if (pwr == 0) return 1; //base case
    ll sq = powerrecursion(base, pwr / 2); //recursive call
    sq *= sq;
    if (pwr % 2) sq *= base; //if power is odd
    return sq;
    // (!(pwr % 2)) base *= base;
    //return base * powerrecursion (base , pwr /= 2);
}

ll power(ll base, ll pwr) {
    ll ans = 1;
    //pwr will be 0 in the last place because i'm dealing with integers so the last power will be 0
    //so it becoms 1 and i'm including this case in the odd if the pwr is 0
    while (pwr) {
           //case it's odd
          //including 1 that must go through at last  to load the ans with the calculated base
          //also if it's odd i must minus one power from it and then it becoms negative
      if (pwr % 2 != 0) ans *= base;
      
      //at both cases after minus to become even from odd or it's already even
      base *= base;
      pwr /= 2; 

   }
    return ans;
}
ll sumPows(ll n, ll p) {
    if (p == 0)return 0;
    if (p % 2 == 1) return n * (1 + sumPows(n, p - 1));
    ll half = sumPows(n, p / 2);
    return half * (1 + half - sumPows(n, p / 2 - 1));
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool checkPalindrome(vector <int>& v, int i, int j) {
    if (i >= j) return true; //continue without returning false at any case meaning that it's all true
    if (v[i] != v[j]) return false;
    return checkPalindrome(v, i + 1, j - 1);
}
int fib(int n) {
    if (n <= 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
//revesion on stirling and bell
vector <int>primeFactors(ll num) {
    vector<int>factors;
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;

        }
    }
    if (num > 1) factors.push_back(num);
    return factors;

}
bool isprime(ll num) {
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) 
            return false;
    return true;
}
vector <int>devisors(ll num) {
    vector<int>devidnums;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            devidnums.push_back(i);
            if (i != num / i) devidnums.push_back(num / i);
        }
    }

    sort(devidnums.begin(), devidnums.end());
    return devidnums;
}
ll LOG(ll n, ll base) {
    ll cnt = 0;
    while (n) {
        n /= base;
        cnt++;
    }
    return cnt - 1;
}
ll toINT(string s) {
    stringstream ss;
    ss << s;
    ll res = 0;
    ss >> res;
    return res;
    //or use stoi(string) to convert to INT
    //stoi is better than atoi as it takes three barametter with the base
}
string toSTRING(ll num) {
    stringstream ss;
    ss << num;
    string res = ss.str();
    return res;
    //or by using to_string(int val or float val)
}
int tobinary(int decimal) {
	// it's arranged because we dont here leave a postion for new bit, instead we add the  new weight to the result
    int res =0;
    int product = 1;
    while (decimal) {
		//res = res * 10 + decimal % 2;
		res += (decimal % 2)*product; 
		decimal /= 2;

        product *= 10;
    }
	return res;
}
void showpq(pq < int > g) {
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
void showpq2(pq<int, vector<int>, greater<int> > g) {
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
struct comparepairs {
    inline bool operator() (const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second < b.second;
    }
}; //order by second elment of the pair
struct hashFunction {
    size_t operator()(const pair<ll, ll>& x) const {
        return x.first ^ x.second;
    }
	//remember it's the fastest way to remove the duplicates from vector by manually insert to set and then we use assign function from the begining to the end
	//of the set and then we can sort them if we need to
    //    v.erase( unique( v.begin(), v.end() ), v.end() ); //this line can be used to remove the duplicates from vector but it's less efficient
}; // for unorderd_set with pair as c++ does not have unorderd_set for pair
int getCharPosition(string s) {
    return (tolower(s[0]) - 'a' + 1);
	//if we want to know if any char  capital it will be s[i] - 'A' between 0 and 25
	//if we want to know if any char  capital it will be s[i] - 'a' between 0 and 25
	//if we want to know if any char  capital it will be s[i] - '0' between 0 and 9
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------- */


class FOUND {
public:

};
class TEST_CASE {
public:

};
void SudoGetAnswer() {
    //    FOUND solution;
    //    TEST_CASE test;
  
}
int main(){
    untie
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t =1; /*cin >> t;*/
    while (t--) {
        //        SudoGetAnswer();
    }
}//end main

/*---------------------------------------------------------------------------------------------------------------------------------------------------- */
/*
trying to get the proper pattern for the string
               string s;
                cin >> s;
                regex reg("\w*h\w*e\w*l\w*l\w*o\w*");//"\w*h\w*e\w*l*o\w*"
                string ss = searchregex(s, reg) ? "YES" : "NO";
                cout << ss;
               */
/*
                 //another regex fun
                   //smatch match;
                      regex_match(str, reg);
                           if (regex_match(str, reg))
                               cout << "Good\n" ;
                           else
                               cout << "Bad\n";
                           // str = match.suffix().str();
                           regex_search(str, match, reg);
                           if (match.ready())
                               cout << "Good\n";
                           else
                               cout << "Bad\n";

                                while (first != end) {
                                       // smatch match = *first;
                                        //cout << match.str();
                                        cout << (*first).str() <<endl;
                                        first++;
                                        */