#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

void show(node *H);
void add(node *&H, int x);
void delNode(node *&H);
void insertToEnd(node *&H, int x);
void insertToEnd2(node *&H, int x);
void addAfterValue(node *&H, int x, int y);
void addBeforeValue(node *&H, int x, int y);
void delValue(node *&H, int x);
void delBeforeValue(node *&H, int x);


int main()
{
	node * H = NULL;
	add(H, 20);
	add(H, 15);
	add(H, 10);
	show(H);

	delNode(H);
	show(H);

	insertToEnd(H, 35);
	show(H);

	insertToEnd2(H, 40);
	show(H);

	addAfterValue(H, 20, 25);
	show(H);

	addBeforeValue(H, 15, 10);
	show(H);

	delValue(H, 20);
	show(H);

	delBeforeValue(H, 35);
	show(H);

	system("pause");
}

void show(node *H) {
	node *P = H;
	while (P != NULL) {
		cout << P->val << " -> ";
		P = P->next;
	}
	cout << "NULL" << endl;
}

void add(node *&H, int x) {
	node * P = new node;
	P->val = x;
	P->next = H;
	H = P;
}

void delNode(node *&H) {
	if (H != NULL) {
		node *P = H;
		H = H->next;
		delete P;
	}
}

void insertToEnd(node *&H, int x) {
	node * P = new node;
	P->val = x;
	P->next = NULL;
	if (H == NULL) {
		H = P;
	}
	else {
		node * E = H;
		while (E->next != NULL) {
			E = E->next;
		}
		E->next = P;
	}
}

void insertToEnd2(node *&H, int x) {
	if (H == NULL) {
		add(H, x);
	}
	else {
		node * E = H;
		while (E->next != NULL) {
			E = E->next;
		}
		add(E->next, x);
	}
}

void addAfterValue(node *&H, int x, int y) {
	if (H != NULL) {
		node * P = H;
		while (P != NULL && P->val != x) {
			P = P->next;
		}
		if (P != NULL) {
			add(P->next, y);
		}
	}
}

void addBeforeValue(node *&H, int x, int y) {
	if (H != NULL) {
		if (H->val == x) {
			add(H, y);
		}
		else {
			node * P = H;
			while (P->next != NULL && P->next->val != x) {
				P = P->next;
			}
			if (P->next != NULL) {
				add(P->next, y);
			}
		}
	}
}

void delValue(node *&H, int x) {
	if (H != NULL) {
		if (H->val == x) {
			delNode(H);
		}
		else {
			node * P = H;
			while (P->next != NULL && P->next->val != x) {
				P = P->next;
			}
			if (P->next != NULL) {
				delNode(P->next);
			}
		}
	}
}

void delBeforeValue(node *&H, int x) {
	if (H != NULL && H->next != NULL) {
		if (H->next->val == x) {
			delNode(H);
		}
		else {
			node * P = H;
			while (P->next->next != NULL && P->next->next->val != x) {
				P = P->next;
			}
			if (P->next->next != NULL) {
				delNode(P->next);
			}
		}
	}
}