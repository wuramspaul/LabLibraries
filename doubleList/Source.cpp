#include <iostream>  // ����������� ����������� ���������� 
using namespace std; // ����������� ������������ ��� std 

int correctnum; // ������� ����� ���

struct doublelist {  // �������� ��������� ��� ���
	int num;          // ���������� ������ ��� ����������� ���� ���        
	float data;       // ���������� �������� ���� ���
	doublelist* next; // ��������� �� ��������� ���� ���
	doublelist* prev; // ��������� �� ���������� ���� ���
};

int menu();         // �������� ������� ��� ������ ���� ��� ���
int menu_input();   // �������� ������� ��� ����� ������ � ����

doublelist* CreateDoubleList();     // ������� �������� ��������� �������� ���
void DeleteDoubleList(doublelist*); // ������� �������� ���
void AddToDoubleList(doublelist*);  // ������� ���������� �������� � ���
void PrintDoubleList(doublelist*);  // ������� ������ ���
void SearchInDoubleList(doublelist*, float);// ������� ������ �� �������� � ���
int SaveDoubleList(); // ������� ���������� � ���� ���
int LoadDoubleList(); // ������� �������� ��� �� ����� 
void deleteDouble(doublelist*);       // ������� �������� ������������� ���������
doublelist* deleteElem(doublelist*); // ������� �������� ��������
int deleteKEDoubleList(doublelist* root, int k); // �������� � ���������
int deleteKEDoubleListBack(doublelist* dl, int k); // �������� � ���������

int main() {
	system("cls");
	// ������� ������� ��� ������ �������� ��� ���, 
	// ���� �� ������� ����� �� ���������
	while (menu() != -1);
	return 0;
}

doublelist* CreateDoubleList() {   // ������� �������� ��������� �������� ���
	doublelist* root = new doublelist;  // ������ ����� ���� ���
	root->num = correctnum = 1;         // ����������� ������� ����� � ���������� ��� � ����
	cout << "Enter value to root node : "; // ������ ������ �������� 
	cin >> root->data;   // ���������� ��� �������� � data
	root->next = nullptr; //������������� ������ �� ��������� ������� nulptr
	root->prev = nullptr; //������������� ������ �� ���������� ������� nulptr 
	return root; //��������� ��������� ����
}

void DeleteDoubleList(doublelist* root) { // ������� �������� ���
  // ���� �������� ������ �� �������������� ���, �� ��������� ������� 
	if (root == nullptr) return;
	// ���������� �������� ��� ������� ���� �� ����� �� ����� ���
	if (root->next != nullptr) DeleteDoubleList(root->next);
	free(root);   // ����� ����� �� ����� ���, ����������� ������ ��������� ��������, 
	--correctnum; // ��������� ���������� ���������
	return;       // ����������� �������, ���� ��� ��� ���� ���, �� ������� ��� � ��� ����� ...  
}

void AddToDoubleList(doublelist* root) {  // ������� ���������� �������� � ���
	doublelist* node = new doublelist;  //������ ����� ���� ���
	cout << "Enter value to new node : "; // ������ ������ ��������
	cin >> node->data;  // ������ ��� �������� � data
	node->num = ++correctnum; // ����������� ������� �����, � ���������� � num
	// ������������� ��������� ���������� ��������
	// �� ��� �� ������� ��������� �������� ����
	node->next = root->next;
	// ������������� ��������� ����������� ����
	// �� �������� ���� ���
	node->prev = root;
	// ������������� ��������� ���������� �������� � ��������� ����
	// �� ���� ������� �� �������
	root->next = node;
}

void PrintDoubleList(doublelist* root) {
	if (root == nullptr) { // ��������� ���������� �� ���
		cout << "Double List is void" << endl;
		return;
	}
	// ������� �������� � ��� �����
	cout << root->num << " : " << root->data << endl;
	// ���� ���� ������ �������� ���������� ��������
	if (root->next != nullptr) PrintDoubleList(root->next);
}

doublelist* deleteElem(doublelist* root) {
	root->prev->next = root->next;
	if (root->next != nullptr) root->next->prev = root->prev;
	doublelist* temp = root->prev;
	free(root);
	return temp;
}

void SearchInDoubleList(doublelist* root, float x) {
	if (root == nullptr) return;
	if (root->data == x) cout << "Find in " << root->num << endl;;
	if (root->next != nullptr) SearchInDoubleList(root->next, x);
	return;
}

void deleteDouble(doublelist* root) {
	if (root == nullptr) return;
	float x = root->data;
	doublelist* temp = root->next;
	while (temp != nullptr)
	{
		if (temp->data == x) temp = deleteElem(temp);
		temp = temp->next;
	}
	if (root->next != nullptr) deleteDouble(root->next);
}

int deleteKEDoubleList(doublelist* root, int k) {
	doublelist* temp;
	while (k != 0) {
		temp = root->next;
		temp->prev = root->prev;
		free(root);
		root = temp;
		k--;
	}
	return 0;
}

int deleteKEDoubleListBack(doublelist* dl, int k) {
	doublelist* temp;
	while (k != 0) {
		temp = dl->prev;
		if (temp != nullptr) temp->next = nullptr;
		delete dl;
		dl = temp;
		k--;
	}
	return 0;
}

// ������� �������� ������� M ��������
void DeleteMElem(doublelist* root, int m) {
	// ������ ���������� ������� ����� ������� 
	// ������� ������ ��������  
	int i = 1;
	doublelist* temp;
	// ������� �� ��������� ���
	while (root != nullptr) {
		// ���� ����� M-� �������, �����
		if (i % m == 0) {
			// ������������ ���������
			temp = root;
			root->prev->next = root->next;
			if (root->next != nullptr) root->next->prev = root->prev;
			root = root->next;
			// ������� �������
			delete temp;
		}
		else
		{
			root = root->next;
		}
		// ����������� ������� 
		i++;
	}
}

int menu() {
	// ������ ����������� ���������� �� ������ ���
	static doublelist* dl;
	// ������ ����������� ��������� �� ������ ���
	// ����� ������� dl - ��������� �� ����� ���,
	// � root_dl - ��������� �� ������ ���
	static doublelist* root_dl;
	system("cls");
	switch (menu_input())
	{
	case 1:
		root_dl = CreateDoubleList();
		dl = root_dl;
		system("cls");
		return 1;
		break;
	case 2:
		char c;
		cout << "Are you sure? (y/n) "; cin >> c;
		if (c == 'y') {
			dl = deleteElem(dl);
		}
		return 2;
		break;
	case 3:
		// ����� dl, ��� ������ �� ������� ����� �������� ����� �������� ����� ����
		AddToDoubleList(dl);
		dl = dl->next;
		return 2;
		break;
	case 4:
		system("cls");
		PrintDoubleList(root_dl);
		system("pause");
		return 2;
		break;
	case 5:
		float x; cout << "Enter value : "; cin >> x;
		SearchInDoubleList(root_dl, x);
		system("pause");
		return 5;
	case 8:
		cout << "Delete double ...";
		deleteDouble(root_dl);
		return 8;
		break;
	case 9:
		cout << "Delete m elem ...\n";
		int m; cout << "Enter m : "; cin >> m;
		DeleteMElem(root_dl, m);
		return 9;
		break;
	case 10:
		cout << "deleteKEDoubleListBack ...\n";
		int k; cout << "Enter K : "; cin >> k;
		deleteKEDoubleListBack(dl, k);
		return 10;
		break;
		
	case 0:
		return -1;
		break;
	}
	return -1;
}

int menu_input() {

	int num = 1;
	cout << num++ << ".Create" << endl;
	cout << num++ << ".DeleteElem" << endl;
	cout << num++ << ".AddNode" << endl;
	cout << num++ << ".Print" << endl;
	cout << num++ << ".Search" << endl;
	cout << num++ << ".Save " << endl;
	cout << num++ << ".Load " << endl;
	cout << num++ << ".DeleteDouble" << endl;
	cout << num++ << ".DeleteMElem" << endl;
	cout << num++ << ".deleteKEDoubleListBack" << endl;

	//TODO swap

	cout << 0 << ".Exit" << endl;

	cout << endl << "Please enter value : ";

	int n; cin >> n;
	return n;
}