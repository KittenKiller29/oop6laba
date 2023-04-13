#pragma once
#include<iostream>
template<class T> class Storage {//������ ������ ����������, ���������� �����������-������, �������-������
public:

	Storage() {//����������� �� ���������
		size = 0;
		mas = new T[size];
	}
	Storage(int a) {//����������� � �����������
		size = a;
		mas = new T[size];
	}
	Storage(const Storage& copy) {//����������� �����������
		size = copy.size;
		mas = new T[size];
		for (int i = 0; i < size; ++i)
			mas[i] = copy.mas[i];
	}
	~Storage() {
		delete[] mas;
	}
	
	void pushObject(int ind, T value);//���������� �������� � ��������� ��� ������������ ��������
	void setObject(int ind, T* value);//���������� �������� ������� ����������������� ��������
	T* deleteObject(int ind);//���������� � ���������
	T getObject(int ind);//���������� ��� ��������
	int getSize();//��������� ������� ����������
private:
	T* mas;//��������� �� ������
	int size;
};
template<class T>
void Storage<T>::pushObject(int ind,T value) {

	int tmpind = ind;						  
	if (tmpind < 0)//���������� ������������� ������� � ����������� ��������				  
		tmpind = 0;							  
	else if (tmpind > size)//���������� ������������� ������� � ����������� ��������			  
		tmpind = size;						  
	T* newmas = new T[size + 1];			  
	for (int i = 0; i < tmpind; i++)//������ � ����� ������ ��������� �� ����������� �������	  
		newmas[i] = mas[i];	  
	newmas[tmpind] = value;//������ � ����� ������ ������ ������� ��� ���������� ��������		  
	for (int i = tmpind; i < size; i++)	//������ � ����� ������ ���� ��������� ������� ����� ����������� �������	  
		newmas[i + 1] = mas[i];				  
	delete[] mas;//����������� ������ �� ������� �������				  
	mas = newmas;							  
	size++;									  
}											  
template<class T>
T* Storage<T>::deleteObject(int ind) {
	int tmpind = ind;
	if (size == 1)
		return nullptr;
	else if (tmpind >= size)//���������� ������������� ������� � ����������� ��������
		tmpind = size - 1;
	else if (tmpind < 0)//���������� ������������� ������� � ����������� ��������
		tmpind = 0;
	T* newmas = new T[size - 1];
	T elem = mas[tmpind];//���������� ���������� ������� �� ��������� ���������� ��� ��� �������� �� ������ 
	for (int i = 0; i < size; i++) {
		if (i < tmpind)//������ � ����� ������ ���� ��������� �� ����������� �������
			newmas[i] = mas[i];
		else if (i > tmpind)//������ � ����� ������ ���� ��������� ����� ����������� �������
			newmas[i - 1] = mas[i];
	}
	delete[] mas;//������������ ������ �� ������� �������
	mas = newmas;//������ ������ ������� � mas
	size--;
	return &elem;//������� ���������� �������
}
template<class T>
T Storage<T>::getObject(int ind) {
	if (size == 0)
		return nullptr;
	else if (ind >= size)//���������� ������������� ������� � ����������� ��������
		return mas[size - 1];
	else if (ind <= 0)//���������� ������������� ������� � ����������� ��������
		return mas[0];
	return mas[ind];
}
template<class T>
int Storage<T>::getSize() {
	return size;
}
template<class T>
void Storage<T>::setObject(int ind, T* value) {
	if (size == 0)
		return;
	else if (ind <= 0)//���������� ������������� ������� � ����������� ��������
		mas[0] = *value;
	else if (ind >= size)//���������� ������������� ������� � ����������� ��������
		mas[size - 1] = *value;
	else
		mas[ind] = *value;
}



