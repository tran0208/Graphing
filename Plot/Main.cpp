#include "Main.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <stdexcept>

using namespace System::IO;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms; 
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{



	// The important lines:
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
    //printf("Hello World!");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Plot::Main Form1;
	Application::Run(%Form1);



	return 0;

}



    System::Void Plot::Main::button1_Click(System::Object^  sender, System::EventArgs^  e)
    { 
		try 
        { 
			//show the open file dialog to user
			//this->FileDialogA->Title = "Input Data";
			//this->FileDialogA->FileName = ""; 
			DialogResult = this->FileDialogA->ShowDialog();
            if (DialogResult == Windows::Forms::DialogResult::OK)
            {
                t = 0;
				this->RollingPointPairListObj->Clear();
				StreamReader^ sr = gcnew StreamReader(this->FileDialogA->FileName);
				String^ line = sr->ReadLine();
				String^ s1;
				String^ s2;
				cli::array<String^>^ pieces;
				double value1;
				double value2;
				while (line != nullptr)    //sr->Peek() >= 0
				{
					Console::WriteLine(line);

					pieces = line->Split(',');
					if (pieces->Length > 1)
					{
						//only input the first two columns 
						s1 = pieces[0];
						s2 = pieces[1];
						try
						{
							value1 = Convert::ToDouble(s1);
							value2 = Convert::ToDouble(s2);
						}
						catch (FormatException^ ex)
						{
							value1 = 0;
							value2 = 0;
						}
						t = t + 1;
						this->RollingPointPairListObj->Add(value1, value2, this->t);


						//Save largest and smallest value in the y axis
						if (this->trackYMAX < value2)
						{
							this->trackYMAX = value2;
							this->yscale->Max = this->trackYMAX + minorYStep;
						}
						if (this->trackYMIN > value2)
						{
							this->trackYMIN = value2;
							this->yscale->Min = this->trackYMIN - minorYStep;
						}
					}

					line = sr->ReadLine();

				}
				sr->Close();

				this->zedGraphObj->Refresh();




            }




        }
        catch( Exception ^ex)
        {
           
        } 
    }



   System::Void Plot::Main::button2_Click(System::Object^  sender, System::EventArgs^  e)
   {
	   //double value = ((rand() % 99) + 1) / 100.0;  
	   try
	   {
           this->inputValue = Convert::ToDouble(textBox1->Text);  

		   cout << this->inputValue << " \n";
		   this->RollingPointPairListObj->Add(this->t , this->inputValue , this->t);
		   //this->zedGraphObj->AxisChange();
 

           //Save largest and smallest value in the y axis
           if (this->trackYMAX < this->inputValue)
           {
			   this->trackYMAX = this->inputValue;
			   this->yscale->Max = this->trackYMAX + minorYStep;
           } 
		   if (this->trackYMIN > this->inputValue)
		   {
			   this->trackYMIN = this->inputValue;
			   this->yscale->Min = this->trackYMIN - minorYStep;
		   }

 

           if (t > XLENGTH) 
           { 
			   this->xscale->Max = t ;
			   this->xscale->Min = t - XLENGTH + MINORXSTEP;
           } 
          
		   label1->Text = "x = " + Convert::ToString(t);
		   this->t++;

		   this->zedGraphObj->Refresh();

		  // this->xScale->Max = this->currentX;
		  // this->xScale->Min = this->xScale->Max - XLENGTH * this->ts;

		   //vector<double> v = { 5, 2, 8, 10, 9 };
		   //int maxElementIndex = std::max_element(v.begin(), v.end()) - v.begin();
		  //int maxElement = *std::max_element(v.begin(), v.end());



       }
	   catch (FormatException^ ex)
       {
		   textBox1->Text = "";
	   }  
   }



    System::Void Plot::Main::button3_Click(System::Object^  sender, System::EventArgs^  e) 
    {
		Close();
	}



