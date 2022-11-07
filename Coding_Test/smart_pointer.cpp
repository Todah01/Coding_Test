#if 1
#include <iostream>
#include <memory>

using namespace std;

class Person {
private:
	string name_;
	int age_;

public:

	Person(const string& name, int age); // ���� Ŭ���� �������� ����
	~Person() { cout << "�Ҹ��ڰ� ȣ��Ǿ����ϴ�." << endl; }

	void ShowPersonInfo();
};

int main()
{
	#pragma region unique_ptr
	// unique_ptr
	unique_ptr<int> ptr01(new int(5)); // int�� unique_ptr�� ptr01�� �����ϰ� �ʱ�ȭ��.
	auto ptr02 = move(ptr01);          // ptr01���� ptr02�� �������� ������.
	
	// unique_ptr<int> ptr03 = ptr01;  // ���� �����ڸ� �̿��� ����� ������ �߻���Ŵ. 
	ptr02.reset();                     // ptr02�� ����Ű�� �ִ� �޸� ������ ������.
	
	// EX
	unique_ptr<Person> hong = make_unique<Person>("�浿", 29);
	hong->ShowPersonInfo();
	#pragma endregion

	cout << "-----------" << endl;

	#pragma region shared_ptr
	shared_ptr<int> ptr03(new int(5)); // int�� shared_ptr�� ptr01�� �����ϰ� �ʱ�ȭ��.

	cout << ptr03.use_count() << endl; // 1

	auto ptr04(ptr03);                 // ���� �����ڸ� �̿��� �ʱ�ȭ

	cout << ptr04.use_count() << endl; // 2

	auto ptr05 = ptr03;                // ������ ���� �ʱ�ȭ

	cout << ptr05.use_count() << endl; // 3  
	#pragma endregion

	return 0;
}

// ���� Ŭ���� �������� ����
Person::Person(const string& name, int age) {
	name_ = name;
	age_ = age;

	cout << "�����ڰ� ȣ��Ǿ����ϴ�." << endl;
}

void Person::ShowPersonInfo() {
	cout << name_ << "�� ���̴� "
		<< age_ << "���Դϴ�." << endl;
}
#endif