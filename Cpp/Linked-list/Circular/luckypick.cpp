//****************************************************************************
//                       Name: Ajay Dinakar Kandavalli
//                       Program name:Lucky pick
//Question: Consider  there  are n criminals(numbered  from  1 to  n)waiting  to  be 
//judgedin acourt. The  order  to judgethem is decided using the following way:
//n peoplesit in a circle. The Judgestartscounting fromperson 1 and go in 
//clockwise directionand skip person 2 and person 3. The fourth personreached 
//is pickedand removed from the circle, i.e. a certain number of people are 
//skipped and the next person is picked.The countingrestarts with person 5 and
//the next fourth person to pickis person 8......Eventually, a single person 
//remains(this guy will be set free, LOL). 
//Strategy:Used a circular linked list concept which use create,delete and show function
//****************************************************************************
#include<iostream>
using namespace std;
//class defination
class  criminal_list
{
	struct node
	{
		int criminal_ID;
		node *next;
	}*head;
public:
	criminal_list()
	{
		head = NULL;
	}
	void add(int data)
	{
		node *temp, *temp1;
		if (head == NULL)
		{
			temp = new node;
			temp->criminal_ID = data;
			head = temp;
			temp->next = head;
		}
		else
		{
			temp = head;
			while (temp->next != head)
				temp = temp->next;
			temp1 = new node;
			temp1->criminal_ID = data;
			temp1->next = head;
			temp->next = temp1;
		}
	}
int delet(int l,int m)
	{
		node *temp,*temp2;
		temp = head;
		while (l >= 2)
		{
			for (int i = 1; i < m; i++)
			{
				temp = temp->next;
			}
			if (head->criminal_ID == temp->next->criminal_ID )
			{	
				head = head->next;
				temp2 = temp->next;
				temp->next = temp2->next;
				cout <<"criminal no. "<<temp2->criminal_ID << " is picked "<< endl;
				delete temp2;
				temp = temp->next;
			}
			else
			{
				temp2 = temp->next;
				temp->next = temp2->next;
				cout <<"criminal no."<< temp2->criminal_ID << " is picked"<< endl;
				delete temp2;
				temp = temp->next;
			}
			l--;
		}
		return temp->criminal_ID;
	}
	void show()
	{
		node *temp;
		temp = head;
		
		if (temp == NULL)
			cout << "\nList not exist";
		cout <<"criminal no."<< temp->criminal_ID;
		temp = temp->next;
		while (temp != head)
		{
			cout << " - criminal no." << temp->criminal_ID;
			temp = temp->next;
		}
		cout << endl;
	}
};
void main()
{
	criminal_list l;
	int  n1,n2;
	cout << "enter number of criminals " << endl;
	cin >> n1;
	cout << "enter number of criminals to skip in each step"<<endl;
	cin >> n2;
	cout << "===========================================================" << endl;
	cout << "there are " << n1 << " criminals to judge" << endl;
	cout << "there are " << n2 << " criminals to skip in each step";
	cout << " and every " << (n2 + 1) << "th criminal is picked and deleted  from list";
	cout << endl;
	for (int i = 1; i <= n1; i++)
	{
		l.add(i);
	}
	cout << "===========================================================" << endl;
	cout << endl;
	cout << "Criminals in the list are positioned  as below"<<endl;
	cout << endl;
	l.show();
	cout << endl;
	cout << endl;
	cout << "list of criminals to be judged in the order that they are picked" << endl;
	cout << endl;
	int j = l.delet(n1,n2);
	cout << endl;
	cout << endl;
	cout << "the lucky criminal set free is criminal no." << j<<endl;

}
