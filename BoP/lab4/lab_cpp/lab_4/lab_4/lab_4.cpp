//������������ ���� ��� ������������� ������������� �����, �� �������� ������ ������: 
//���� �������, ��������� ������� �������, ��������� ������� �������.
//���� ������� ���� ����������� � ����������, ���� � ����� ���� �����_������� ���������_�������_������� / ���������_�������_�������(���������, �3 2 / 5�), 
//������� ���� ������������, ����� ��������� ��'����-�����, ������� ���� ������ ��������/���������, ������ ��� ��������� ����������� �������. 
//��������� ��������, ��� ������� ��� ������������ ����� � ��������� �� ���� (� ������������� ��������������� ��������� �+�). 
//�������� ������� ������������� ������ ��������� ��� �������, �������� �� �������� ����� 
//(� ������������� ��������������� ������������ ��������� ���������� ��������� �<<�).

#include "Number.h"
#include <iostream>

int main() {

	Number a("3 2 / 5");
	Number b("4 3 / 5");

	Number c = a + b;

	cout << "First num: " << endl;
	a.outputFraction();

	cout << "Second num: " << endl;
	b.outputFraction();

	cout << "Nums after +: " << endl;
	c.outputFraction();

}