/*
참고
https://velog.io/@shin421179/%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8%EB%A5%BC-%EC%9C%84%ED%95%9C-C-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B2%98%EB%A6%AC

*/

#include<iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    //////////////////////////////////////////////
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // stdio의 스트림과 동기화 해제 -> 속도 상승

    //////////////////////////////////////////////
    
    int N;
    while(cin >> N){
    	cout << N;
    }  
    // EOF까지 받기

    string str;
    while(getline(cin, str)){
        cout << str;
    }
    // cin.ignore() 사용 권장

    while(!cin.eof()){
        cin >> str;
        cout << str;
    }

    //////////////////////////////////////////////
    
    double n = 12.6374;
    cout<<fixed;
    cout.precision(0); // 일의 자리까지 반올림해서 출력
    cout << n << '\n'; // 13
    cout.precision(1); // 소수점 첫 자리까지 반올림해서 출력
    cout << n << '\n'; // 12.6
    cout.precision(2); // 소수점 둘째 자리까지 반올림해서 출력
    cout << n << '\n'; // 12.64
 
    //////////////////////////////////////////////
    
    // 3. 문자열 수정
    string ex = "abcd123 hello !@#$ abcd 1234";
    // 3-1. 특정 인덱스를 치환
    // str.replace(n, k, str2)
    // 인덱스 n부터 k개를 str2로 치환
    // 리턴 없이 str을 수정함
    cout << ex.replace(14, 4, "cpp") << '\n'; // abcd123 hello cpp abcd 1234
    
    // 3-2. 특정 인덱스 삭제
    cout << ex.replace(8, 6, "") << '\n'; // abcd123 cpp abcd 1234
    cout << ex.erase(7,1) << '\n';        // abcd123cpp abcd 1234
    // 인덱스 대신 iterator 사용해도된다. iterator도 오버로딩되어 있음.
    cout << ex.erase(7) << '\n';          // abcd123 //갯수 안 쓰면 끝까지 삭제

    // 3-3. 문자의 대소문자 변환
    string ex2 = "abAB123!@#$";
    // 아스키 값 리턴
    cout << ex2[0] << " -> " << (char)toupper(ex[0]) << '\n'; // a -> A
    cout << ex2[2] << " -> " << (char)tolower(ex[2]) << '\n'; // A -> c
    cout << ex2[10] << " -> " << (char)toupper(ex[11]) << '\n'; // $ -> A
    // 알파벳 아닌 경우엔 l, L 리턴

    string ex3 = "int";
    // 3-4. 문자열 삽입
    // str.insert(n, str2) n번째 앞에 str2 삽입
    cout << ex3.insert(2, "ser") << '\n'; // insert

    //////////////////////////////////////////////

    // isdigit(chr)
    // isalpha(chr)
    // 파마리터 : char형
    // 리턴 : 0 또는 1

    //////////////////////////////////////////////
    // 5. 문자열 탐색, 추출
    string ex5 = "hello string";

    // 5-1. 부분문자열 추출
    // str.substr(pos, count = npos)
    // 참고로 substr은 매우 느리다
    cout << ex5.substr(0, 5) << '\n';
    cout << ex5.substr(0) << '\n';
    cout << ex5.substr(0, string::npos) << '\n';

    //////////////////////////////////////////////

    // 5-2. 부분문자열 탐색
    string ex5_2 = "hello cpp world cpp";
    // 인덱스 반환, 없으면 string::npos 리턴
    // find(substr, n) n부터 substr의 인덱스
    cout << ex5_2.find("cpp") << '\n';
    cout << ex5_2.find("cpp", 7) << '\n';
    cout << (ex5_2.find("java") == string::npos) << '\n';
    cout << ex5_2.find_first_of("cpp") << '\n'; // 문자들이 처음 등장하는 시작 인덱스
    cout << ex5_2.find_first_not_of("cpp") << '\n'; // 문자들이 아닌 첫 인덱스
    cout << ex5_2.find_last_of("cpp") << '\n'; // 문자들 중 마지막 등장하는 마지막 인덱스
    cout << ex5_2.find_last_not_of("cpp") << '\n'; // 문자들 아닌 마지막 인덱스

    //////////////////////////////////////////////
    
    // 5-3. 특정문자열 갯수 카운트
    // #include <regex> 필요
    
    string ex5_3 = "hello java and spring boot";

    regex re("a"); // 타겟 문자열
    auto end = sregex_iterator();
    auto iter = sregex_iterator(ex5_3.begin(), ex5_3.end(), re);

    cout << "\'a\' count : " << distance(iter, end) << '\n';

    //////////////////////////////////////////////

    // split과 trim은 C++에 없으니까 구현 필요함
}

stack<string> split(string& str, char d) {
    stringstream ss(str);
    string token;
    vector<string> splited;
    while(getline(ss, token, d)) {
        splited.push_back(token);
    }
    return splited;
}

string trim(string str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}