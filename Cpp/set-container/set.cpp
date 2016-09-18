//********************************************************************************************
//                             Ajay Dinakar Kandavalli      
//                       Discrete Structures and Analysis
//          Program to demonstrate set operations using  sets container in c++ stl library
//********************************************************************************************
#include< iostream>
#include<fstream>
#include<set>
using namespace std;
int main()
{
	set <int> A, B, U, AUB, AIB, A_B, B_A, Acomp, Bcomp;//declaring set containers
	set<int>::iterator itA, itB, itU, itAUB, itAIB, itA_B,  itB_A,itAcomp,itBcomp;//declaring iterators
	int number;
	int countA = 0, countB = 0, countU = 0, countAUB = 0, countA_B = 0, countAIB = 0, countB_A = 0, countAcomp = 0, countBcomp = 0;//used for getting sets format
	ifstream inputfile;
	inputfile.open("input.dat");//input file 
	ofstream outputfile;
	outputfile.open("kandavalli_ajay.txt");//output file 
	//*********************************************************************
	//           Reading elements from input file to setA
	//**********************************************************************
	inputfile >> number;
	while (number != -999)     //read numbers before -999 from input file
	{ 
		A.insert(number);//this will not read  -999
		inputfile >> number;
	}
	outputfile << "Ajay Dinakar Kandavalli\n";
	//******************sending set A to output file****************************
	for (itA = A.begin(); itA != A.end(); itA++)
	{
		countA++;
	}

	outputfile << "Set A = {";
	int i=1;
	for (itA = A.begin(); itA != A.end(); itA++)//used for getting elements in sets format
	{
		if (i < countA)
	    {
	    outputfile << *itA << ",";
	    i++;
	    }
	    else 
	    outputfile << *itA ;
     }
	outputfile << "}\n";
	//*********************************************************************
	//           Reading elements from input file to setB
	//**********************************************************************

	while (!inputfile.eof()) //read elements after -999 to end of the file to set B

	{
		inputfile >> number;
		B.insert(number);
	}
	
	

//********sending set B elements to output file**************
	for (itB = B.begin(); itB != B.end(); itB++)
	{
		countB++;
	}

	outputfile << "Set B = {";
	
	int j = 1;
	for (itB = B.begin(); itB != B.end(); itB++)//used for getting elements in sets format
	{
	if (j < countB)
	{
	outputfile << *itB << ",";
	j++;
    }
	else 
	outputfile << *itB ;
	}
	outputfile << "}\n";
	inputfile.close();
	
	//****************************************************
	//           set A Union set B
	//****************************************************
	for (itA = A.begin(); itA != A.end(); itA++)
	  {
		AUB.insert(*itA);
	  }
    for (itB = B.begin(); itB != B.end(); itB++)
       {
		AUB.insert(*itB);
	   }

	for (itAUB = AUB.begin(); itAUB != AUB.end(); itAUB++)// for getting elements in sets format
	{
		countAUB++;
	}
	int k = 1;
	outputfile << "The Union of sets A and B={";
	for (itAUB = AUB.begin(); itAUB != AUB.end(); itAUB++)	
	   if (k < countAUB)
         {
	     outputfile << *itAUB << ",";
	     k++;
	     }
	   else
	   outputfile << *itAUB ;
    outputfile << "}\n";
	//******************************************************************
	//               A intersection B
	//******************************************************************
	for (itA = A.begin(); itA != A.end(); itA++)
		for (itB = B.begin(); itB != B.end(); itB++)
        {
			if (*itA == *itB)
			AIB.insert(*itA);
		}
	for (itAIB = AIB.begin(); itAIB != AIB.end(); itAIB++)//used for getting elements in sets format
	{
		countAIB++;
	}
	int l = 1;
	outputfile << "The intersection of sets A and B={";
	for (itAIB = AIB.begin(); itAIB != AIB.end(); itAIB++)
		if (l < countAIB)
		{
			outputfile << *itAIB << ",";
			l++;
		}
		else
			outputfile << *itAIB ;
            outputfile << "}\n";
	// **************************************************************************
	//                        set A minus set B
	//***************************************************************************
        int Aincrement = 0;
		for (itA = A.begin(); itA != A.end(); itA++)
		{
			Aincrement = 0;
			for (itB = B.begin(); itB != B.end(); itB++)
			{
				if (*itA == *itB)
					Aincrement++;

			}
			if (Aincrement == 0)
			{
				A_B.insert(*itA);

			}

		}
	for (itA_B = A_B.begin(); itA_B != A_B.end(); itA_B++)//used for getting elements in sets format
	{
	countA_B++;
	}
    int m = 1;
	outputfile << "A - B={";
	for (itA_B = A_B.begin(); itA_B != A_B.end(); itA_B++)
	if (m < countA_B)
	{
	outputfile << *itA_B << ",";
	m++;
	}
	else
	outputfile << *itA_B ;
    outputfile << "}\n";
	//  **************************************************************/
    //                         set B- set A
	//  **************************************************************/

	 int Bincrement = 0;
	for (itB = B.begin(); itB != B.end(); itB++)
	
	{
		Bincrement = 0;
		for (itA = A.begin(); itA != A.end(); itA++)
		{
			if (*itB == *itA)
				Bincrement++;

		}
		if (Bincrement == 0)
		{
			B_A.insert(*itB);

		}
    }
	for (itB_A = B_A.begin(); itB_A != B_A.end(); itB_A++)//used for getting elements in sets format
	{
		countB_A++;
	}
	
	int n = 1;
	outputfile << "B - A={";
	for (itB_A = B_A.begin(); itB_A != B_A.end(); itB_A++)
	if (n < countB_A)
	{
	outputfile << *itB_A << ",";
	n++;
	}
	else
	outputfile << *itB_A ;

	outputfile << "}\n";
	//***************************************************************************
    //                      A compliment
	//***************************************************************************
	for (int x = 1; x <= 30; x++)
		U.insert(x);

	 int Uincrement = 0;
	for (itU = U.begin(); itU != U.end(); itU++)
	
	{
		Uincrement = 0;
		for (itA = A.begin(); itA != A.end(); itA++)
		{
			if (*itU == *itA)
				Uincrement++;

		}
		if (Uincrement == 0)
		{
			Acomp.insert(*itU);

		}

	}
	for (itAcomp = Acomp.begin(); itAcomp != Acomp.end(); itAcomp++)//used for getting elements in sets format
	{
		countAcomp++;
	}
	int o = 1;
	outputfile << "A complement={";
	for (itAcomp = Acomp.begin(); itAcomp != Acomp.end(); itAcomp++)
		if (o < countAcomp)
		{
			outputfile << *itAcomp << ",";
			o++;
		}
		else
			outputfile << *itAcomp;

	outputfile << "}\n";
	//****************************************************************************
	//                              B compliment
	//****************************************************************************
	 Uincrement = 0;
	for (itU = U.begin(); itU != U.end(); itU++)
	{
		Uincrement = 0;
	 for (itB = B.begin(); itB != B.end(); itB++)
	{
	if (*itU == *itB)
		Uincrement++;

		}
		if (Uincrement == 0)
		{
			Bcomp.insert(*itU);

		}

	}
	for (itBcomp = Bcomp.begin(); itBcomp != Bcomp.end(); itBcomp++)//used for getting elements in sets format
	{
		countBcomp++;
	}
	int p = 1;
	outputfile << "B complement={";
	for (itBcomp = Bcomp.begin(); itBcomp != Bcomp.end(); itBcomp++)
		if (p < countBcomp)
		{
			outputfile << *itBcomp << ",";
			p++;
		}
		else
			outputfile << *itBcomp;
	outputfile << "}\n";
	//outputfile.close();//close output file 
	return 0;

}
