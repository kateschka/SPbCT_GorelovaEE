template <typename T> class vector
{
private:
	T* _array; //��������� �� ������
	int _arraySize; //������ �������

public:
	void push_back(T data)
	{
		T* _result = new T[++this->_arraySize]; //������� ����� ������ �������� ���������+1

		for (int index = 0; index < this->_arraySize; index++)
		{
			if (index != this->_arraySize - 1) //���� �� ��������� ������� �������
			{
				_result[index] = this->_array[index]; //������������ ������� � ����� ������
			}
			else
			{
				_result[index] = data; //���������� ������ � ��������� �������
				break;
			}
		}
		delete[] this->_array; //������� �������� ������
		this->_array = _result; //����������� ������ �� ����� ������
	}

	void clear()
	{
		if (this->_array != nullptr)
		{
			::ZeroMemory(this->_array, this->_arraySize); //��������� ������ ���� ������
		}
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}

	T operator [](int index) //�������� �������� �� �������
	{
		return this->_array[index];
	}

	int size() //�������� ������ �������
	{
		return this->_arraySize;
	}

	vector() //����������� �� �����
	{
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}
};