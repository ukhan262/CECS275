#include "stdafx.h"
#include "DataSet.h"

//returns the mean of dataset
double DataSet::mean()
{
	double avg = 0, total = 0;
	for(int i = 0; i < size; i++)
		total += dataset[i];
	avg = total / size;
	return avg;
}

//returns the minimum value of dataset
int DataSet::min()
{
	sort();
	return dataset[0];
}

//returns the maximum value of dataset
int DataSet::max()
{
	sort();
	return dataset[size - 1];
}

//returns the standard deviation of dataset
double DataSet::standev()
{
	double variValue = variance();
	double stndDev = sqrt(variValue);
	return stndDev;
}

//returns the median value of dataset
double DataSet::median()
{
	int mid = size / 2;
	if(mid%2 == 0)
	{
		return ((dataset[mid-1] + dataset[mid]) / 2.0);
	}
	else
	{
		return dataset[mid];
	}
}

//returns the variance of dataset
double DataSet::variance()
{
	double variValue = 0;
	double meanValue = mean();
	for(int i = 0; i < size; i++)
	{
		variValue += (dataset[i] - meanValue) * (dataset[i] - meanValue);
	}
	variValue /= size;
	return variValue;
}

//returns the size of dataset
int DataSet::getSize()
{
	return size;
}

//constructs the dataset array
DataSet::DataSet(int s)
{
	limit = s;
	dataset = new int[DIGITS];
	size = 0;
}

// PrintAll prints the dataset in either a table=true 
// or one column if table =false
void DataSet::PrintAll(bool table)
{
	cout << "\nData set size = " << size << endl << endl;
	if(table)
	{
		cout << setfill('=') << setw(80);
		cout << " ";
		cout << setfill(' ');
		for(int i = 0; i < size; i++)
		{
			if(i % 10 == 0)
				cout << endl;
			cout << setw(8) << dataset[i];
		}
		cout << endl;
		cout << setfill('=') << setw(80);
		cout << " " << endl;
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << setw(8) << dataset[i] << endl;
		}
	}
}

/* LoadData checks if the file "in" is open and attempts to
load the dataset from the input file. If the file is not
open print "file not open". If the file contains more data the
limit entered, stop attempting to read and return.
*/
void DataSet::LoadData(ifstream &in)
{
	int count = 0;
	int value;
	dataset = new int[DIGITS];
	size = 0;
	if(!in)
	{
		cout << "File not opened! Try again later.\n";
		exit(0);
	}
	if(size < limit)
	{
		while(!in.eof() && size < limit)
		{
			in >> value;
			dataset[size] = value;
			size++;
		}
	}
	sort();
	in.close();
}

// sorts the content of the data
void DataSet::sort()
{
	int temp = dataset[0];
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - 1; j++)
		{
			if(dataset[j] > dataset[j + 1])
			{
				temp = dataset[j];
				dataset[j] = dataset[j + 1];
				dataset[j + 1] = temp;
			}
		}
	}
}