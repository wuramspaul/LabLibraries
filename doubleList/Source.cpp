#include <iostream>  // Подключения стандартной библиотеки 
using namespace std; // Подключения пространства имён std 

int correctnum; // Счётчик узлов ДЛС

struct doublelist {  // Обявляем структуру для ДЛС
	int num;          // Переменная номера для конкретного узла ДЛС        
	float data;       // Переменная значения узда ДЛС
	doublelist* next; // Указатель на следующий узел ДЛС
	doublelist* prev; // Указатель на предыдущий узел ДЛС
};

int menu();         // Обявляем функцию для вызова меня над ДЛС
int menu_input();   // Обявляем функцию для ввода пункта в меню

doublelist* CreateDoubleList();     // Функция создания корневого элемента ДЛС
void DeleteDoubleList(doublelist*); // Функция удаления ДЛС
void AddToDoubleList(doublelist*);  // Функция добавление элемента в ДЛС
void PrintDoubleList(doublelist*);  // Функция вывода ДЛС
void SearchInDoubleList(doublelist*, float);// Функция поиска по значению в ДЛС
int SaveDoubleList(); // Функция сохранения в файл ДЛС
int LoadDoubleList(); // Функция загрузки ДЛС из файла 
void deleteDouble(doublelist*);       // Функция удаление повторяющихся элементов
doublelist* deleteElem(doublelist*); // Функция удаления элемента
int deleteKEDoubleList(doublelist* root, int k); // Удоление К элементов
int deleteKEDoubleListBack(doublelist* dl, int k); // Удоление К элементов

int main() {
	system("cls");
	// Вызваем функцию для выбора действий над ДЛС, 
	// Пока не выберут выход из программы
	while (menu() != -1);
	return 0;
}

doublelist* CreateDoubleList() {   // Функция создания корневого элемента ДЛС
	doublelist* root = new doublelist;  // Создаём новый узел ДЛС
	root->num = correctnum = 1;         // Увеличиваем текущий номер и записываем его в узел
	cout << "Enter value to root node : "; // просим ввести значения 
	cin >> root->data;   // записываем это значение в data
	root->next = nullptr; //устанавливаем ссылку на следующий элемент nulptr
	root->prev = nullptr; //устанавливаем ссылку на предыдущий элемент nulptr 
	return root; //Возращаем созданный узел
}

void DeleteDoubleList(doublelist* root) { // Функция удаления ДЛС
  // Если передали ссылку на несуществующий ДЛС, то возращаем функцию 
	if (root == nullptr) return;
	// Рекурсивно вызываем эту функцию пока на дайдём до конца ДЛС
	if (root->next != nullptr) DeleteDoubleList(root->next);
	free(root);   // Когда дошли ко конца ДЛС, освобождаем память корневого элемента, 
	--correctnum; // Уменьшаем количество элементов
	return;       // Возращаемся обратно, если это был узел ДЛС, то удаляем его и так далее ...  
}

void AddToDoubleList(doublelist* root) {  // Функция добавление элемента в ДЛС
	doublelist* node = new doublelist;  //Создаём новый узел ДЛС
	cout << "Enter value to new node : "; // Просим ввести значения
	cin >> node->data;  // Вводим эти значения в data
	node->num = ++correctnum; // Евеличиваем счётчик узлов, и записываем в num
	// Устонавливаем указатель слудующего элемента
	// на тот на который указывает корневой узел
	node->next = root->next;
	// Устонавливаем указатель предыдущего узла
	// на корневой узел ДЛС
	node->prev = root;
	// Устонавливаем указатель следующего элемента у корневого узла
	// на узел который мы создали
	root->next = node;
}

void PrintDoubleList(doublelist* root) {
	if (root == nullptr) { // Проверяем существует ли ДЛС
		cout << "Double List is void" << endl;
		return;
	}
	// Выводим значение и его номер
	cout << root->num << " : " << root->data << endl;
	// Если есть другие элементы продолжаем выводить
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

// Функция удаления каждого M элемента
void DeleteMElem(doublelist* root, int m) {
	// Создаём переменную которая будет считать 
	// текущий индекс элемента  
	int i = 1;
	doublelist* temp;
	// Проходи по элементам ДЛС
	while (root != nullptr) {
		// Если нашли M-й элемент, тогда
		if (i % m == 0) {
			// Переставляем указатели
			temp = root;
			root->prev->next = root->next;
			if (root->next != nullptr) root->next->prev = root->prev;
			root = root->next;
			// Удаляем элемент
			delete temp;
		}
		else
		{
			root = root->next;
		}
		// Увеличиваем счётчик 
		i++;
	}
}

int menu() {
	// Создаём статическую переменную на корень ДЛС
	static doublelist* dl;
	// Создаём статическую переменую на корень ДЛС
	// Таким образом dl - указывает на конец ДЛС,
	// а root_dl - указывает на начало ДЛС
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
		// Здесь dl, это ссылка на элемент после которого нужно вставить новый узел
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