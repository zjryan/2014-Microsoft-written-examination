#include <iostream>

using namespace std;

struct Node{
	int Value;
	Node* Next;
};

int 
LinkedlistLength(Node* head){
	int Cnt = 0;
	Node* P = head;
	while (P != NULL){
		Cnt++;
		P = P->Next;
	}	
	return Cnt;
}

Node* 
ExtractFinal(Node* head){
	Node* P = head;
	Node* Previous = NULL;
	while (P->Next != NULL){
		Previous = P;
		P = P->Next;
	}
	Previous->Next = NULL;
	return P;
}

void 
SwapLinkedlist(Node* head){
	Node* P = head;
	Node* Ps = P->Next;
	int Cnt;
	int Length;
	Cnt = Length = LinkedlistLength(head);
	Node* Pn = ExtractFinal(Ps);

	while (Cnt > 1){
		Pn->Next = Ps;
		P->Next = Pn;
		Cnt -= 2;
		if (Length % 2 == 0 && Cnt == 2){	
			break;
		}
		else if (Length % 2 == 1 && Cnt == 1){
			break;
		}
		else{
			P = Ps;
			Ps = P->Next;
			Pn = ExtractFinal(P);
		}
	}
}

void
PrintLinkedlist(Node* head){
	Node* P = head;
	while (P != NULL){
		cout << P->Value << ' ';
		P = P->Next;
	}
	cout << endl;
}
