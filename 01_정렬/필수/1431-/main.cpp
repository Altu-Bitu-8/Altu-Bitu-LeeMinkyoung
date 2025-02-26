#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.*/
void sortSN(vector<string>& arr);

int main() {
    int N;
    cin >> N;
    vector<string> arr(N);
    for(int i = 0; i<N; i++) {
        cin >> arr[i];
    }
    sortSN(arr);
    for(int i = 0; i<N; i++) {
        cout << arr[i] << '\n';
    }
}
//첨에 두번째 조건을 어떻게 다룰지 몰라 한참 헤멨다... isdigit()이란거 잘 기억해두기
int digitSum(const string& s) {
    int sum = 0;
    for(char c : s) {
        if(isdigit(c)) {
            sum += c - '0';//숫자가 아스키코드 값으로 들어가는거니까 0의 아스키코드 값 만큼 빼줘야 함
        }
    }
    return sum;
}
bool compare(const string& a, const string& b) {

    //a와 b를 받아서 가장 먼저 둘의 길이 비교. 만약 b(b가 뒤에 위치한 string임!! 기억하자)가 길이가 작다면 return값이 false가 나오고 둘이 바뀜
    if(a.length()!= b.length())
        return a.length() < b.length();
    int aSum = digitSum(a);
    int bSum = digitSum(b);
    //이건 두번째 조건 처리문
    if(aSum != bSum) {
        return aSum < bSum;
    }
    //마지막으로 이건 그냥 아스키코드 대로 비교하는거라 그냥 a<b로 해도 됨
    return a < b;
}


void sortSN(vector<string>& arr) {
    sort(arr.begin(), arr.end(), compare);
}


/*처음에 똑같은 논리로 코드를 작성했으나, compare함수를 안만들고 sort()를 안쓰고 그냥 swap만 써서
 *sortSN함수에 2중 for문에 if문 덕지덕지 해놓았더니 틀림이 나옴...
 *아마 시간 초과거나 if문 덕지덕지 하는 과정에서 부등호 잘못했나봄... 우울띠예...
 */