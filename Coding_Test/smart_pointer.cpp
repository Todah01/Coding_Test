#if 1
#include <iostream>
#include <memory>

using namespace std;

class Person {
private:
	string name_;
	int age_;

public:

	Person(const string& name, int age); // 기초 클래스 생성자의 선언
	~Person() { cout << "소멸자가 호출되었습니다." << endl; }

	void ShowPersonInfo();
};

int main()
{
	#pragma region unique_ptr
	// unique_ptr
	unique_ptr<int> ptr01(new int(5)); // int형 unique_ptr인 ptr01을 선언하고 초기화함.
	auto ptr02 = move(ptr01);          // ptr01에서 ptr02로 소유권을 이전함.
	
	// unique_ptr<int> ptr03 = ptr01;  // 대입 연산자를 이용한 복사는 오류를 발생시킴. 
	ptr02.reset();                     // ptr02가 가리키고 있는 메모리 영역을 삭제함.
	
	// EX
	unique_ptr<Person> hong = make_unique<Person>("길동", 29);
	hong->ShowPersonInfo();
	#pragma endregion

	cout << "-----------" << endl;

	#pragma region shared_ptr
	shared_ptr<int> ptr03(new int(5)); // int형 shared_ptr인 ptr01을 선언하고 초기화함.

	cout << ptr03.use_count() << endl; // 1

	auto ptr04(ptr03);                 // 복사 생성자를 이용한 초기화

	cout << ptr04.use_count() << endl; // 2

	auto ptr05 = ptr03;                // 대입을 통한 초기화

	cout << ptr05.use_count() << endl; // 3  
	#pragma endregion

	return 0;
}

// 기초 클래스 생성자의 정의
Person::Person(const string& name, int age) {
	name_ = name;
	age_ = age;

	cout << "생성자가 호출되었습니다." << endl;
}

void Person::ShowPersonInfo() {
	cout << name_ << "의 나이는 "
		<< age_ << "살입니다." << endl;
}
#endif