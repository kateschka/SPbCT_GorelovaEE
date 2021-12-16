#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <thread>
#include <Windows.h>
#include <locale.h>
#include "Vector.cpp"
#include "../../Dll1/funct.h"

#pragma once
using namespace std;

#define THREADCOUNT 1
HANDLE myMutex;
DWORD WINAPI WriteToFile(LPVOID);
vector<string> parts;

static void WriteToCSV(vector<string> arr)
{
	ofstream out;          // ����� ��� ������
	out.open("2.csv"); // �������� ���� ��� ������
	if (out.is_open())
	{
		for (int i = 0; i < arr.size(); i++)
		{
			string str = arr[i];
			for (int j = 0; j < str.size(); j++)
			{
				out << str[j] << ',';
			}
			out << endl;
		}
	}
	out.close();
	system("attrib +R Release/2.csv"); // ��������� ������� ������ ��� ������
}
static string ReadFromFile()
{
	string line;
	ifstream in("1.txt"); // �������� ���� ��� ������
	if (in.is_open())
	{
		getline(in, line);
	}
	in.close();     // ��������� ����
	return line;
}
static vector<string> DivideLine(string line)
{
	vector<string> parts;
	for (int i = 0; i < line.length(); i += 10) {
		parts.push_back(line.substr(i, 10));
	}
	return parts;
}
DWORD WINAPI WriteToFile(LPVOID lpParam)
{
	DWORD dwCount = 0, dwWaitResult; // ��������� �������� ���������
	while (dwCount < 2)
	{
		dwWaitResult = WaitForSingleObject(
			myMutex,    // handle �� �������
			INFINITE);  // ��� ��������
		switch (dwWaitResult)
		{			
		case WAIT_OBJECT_0: // ����� �������� ���������
			__try {
				WriteToCSV(parts),
					GetCurrentThreadId();
					dwCount++;
			}
			__finally {				
				if (!ReleaseMutex(myMutex))// ���������� �������
				{
					//error
				}
			}
			break;			
		case WAIT_ABANDONED: // ���� ������
			return FALSE;
		}
	}
	return TRUE;
};
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(336, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 52);
			this->button1->TabIndex = 2;
			this->button1->Text = L"������ ���������� ���������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(395, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"��������� ��������� ����������, ������ 503";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(224, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"   ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(13, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(204, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"������� ���� � �����:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(13, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"�������� ������:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(14, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 20);
			this->label5->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(949, 365);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) //������ ������ ����������
	{
		string str = MyFunc::GetTime();
		String^ strg = gcnew String(str.c_str());
		label2->Text = strg;

		string line = ReadFromFile();
		String^ text = gcnew String(line.c_str());
		label5->Text = text;

		parts = DivideLine(line);
		
		HANDLE aThread;
		DWORD ThreadID;		
		myMutex = CreateMutex( // �������� ��������
			NULL,              // �������� ������������ �� ���������
			FALSE,             // ��� ���������
			NULL);             // ��� �����

		if (myMutex == NULL)
		{
			MessageBox::Show(L"������ �������� ��������", L"������!");
		}

		aThread = CreateThread(
			NULL,       // �������� ������������ �� ���������
			0,          // ������ ����� �� ���������
			(LPTHREAD_START_ROUTINE)WriteToFile,
			NULL,       // ��� ���������� ��������
			0,          // default creation flags
			&ThreadID); // �������� id ������

		if (aThread == NULL)
		{
			MessageBox::Show(L"������ �������� ������", L"������!");
		}
		// ������� ����� � �������
		WaitForMultipleObjects(THREADCOUNT, &aThread, TRUE, INFINITE);
		CloseHandle(aThread);
		CloseHandle(myMutex);
	}	
	};
}
