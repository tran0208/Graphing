#pragma once


#include <vector> 
#include <string>
#include <iostream>


namespace Plot 
{


	using namespace std; 
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//Graph appearance 
			this->GraphPaneObj = zedGraphObj->GraphPane;
			this->LineItemObj = zedGraphObj->GraphPane->AddCurve("y", RollingPointPairListObj, Color::Blue, SymbolType::Circle);  
			this->zedGraphObj->IsShowPointValues = true; 
			this->xscale = zedGraphObj->GraphPane->XAxis->Scale;
			this->yscale = zedGraphObj->GraphPane->YAxis->Scale;
			// 

			GraphPaneObj->Title->FontSpec->Size = 14;
		    GraphPaneObj->Title->Text = "y[n] vs n";

			GraphPaneObj->XAxis->Title->FontSpec->Size = 10;
			GraphPaneObj->XAxis->Title->Text = "n";
			GraphPaneObj->XAxis->Title->IsVisible = true;
			GraphPaneObj->XAxis->Title->IsTitleAtCross = true;
			GraphPaneObj->XAxis->Scale->FontSpec->Size = 6;

			GraphPaneObj->YAxis->Title->FontSpec->Size = 10;
			GraphPaneObj->YAxis->Title->Text = "y[n]";
			GraphPaneObj->YAxis->Title->IsVisible = true;
			GraphPaneObj->YAxis->Title->IsTitleAtCross = true;
			GraphPaneObj->YAxis->Scale->FontSpec->Size = 6;
			GraphPaneObj->CurveList->Clear(); 

			//Axis limit
			GraphPaneObj->XAxis->Scale->Min = -this->ts;
			GraphPaneObj->XAxis->Scale->Max = this->XLENGTH + this->ts;
			GraphPaneObj->XAxis->MinorGrid->IsVisible = true;
			GraphPaneObj->XAxis->MajorGrid->IsVisible = true;
			GraphPaneObj->YAxis->Scale->Min = yMin;
			GraphPaneObj->YAxis->Scale->Max = yMax;

			//x-axis tick
			GraphPaneObj->XAxis->Scale->MinorStep = MINORXSTEP * this->ts;
			GraphPaneObj->XAxis->Scale->MajorStep = MAJORXSTEP * this->ts;

			//y-axis tick
			GraphPaneObj->YAxis->Scale->MinorStep = minorYStep;
			GraphPaneObj->YAxis->Scale->MajorStep = majorYStep;
			GraphPaneObj->YAxis->MinorGrid->IsVisible = true;
			GraphPaneObj->YAxis->MajorGrid->IsVisible = true;

			GraphPaneObj->YAxis->Scale->FormatAuto = true;
			GraphPaneObj->YAxis->Scale->Format = "f2";


			//Circular Buffer: with capacity of "XLENGTH" points 
			RollingPointPairListObj = gcnew RollingPointPairList(XLENGTH); 
			LineItemObj = zedGraphObj->GraphPane->AddCurve("y", RollingPointPairListObj, Color::Blue,  SymbolType::Circle );

			LineItemObj->Symbol->Fill = gcnew Fill(Color::White);
			LineItemObj->Symbol->Size = 5;
			//activate the cardinal spline smoothing
			LineItemObj->Line->IsSmooth = true;
			LineItemObj->Line->SmoothTension = 0.5F;
			LineItemObj->Line->Width = 2.0;
 
			//Choosing the right colour for the graph background
			//Give the graph background some style!!!
			GraphPaneObj->Chart->Fill = gcnew Fill(Color::White, Color::WhiteSmoke, -45.0F);
			LineItemObj->Line->Fill = gcnew Fill(Color::LightSkyBlue, Color::MistyRose, 60.0F);


 
			zedGraphObj->AxisChange();
  

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^  zedGraphObj;
	private: System::Windows::Forms::Button^  button1;

	protected:

	protected:

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  myTimer;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::OpenFileDialog^  FileDialogA;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary> 
        ZedGraph::GraphPane ^GraphPaneObj;
	    ZedGraph::RollingPointPairList ^RollingPointPairListObj;
	    ZedGraph::LineItem ^LineItemObj;
	    ZedGraph::Scale ^xscale; 
		ZedGraph::Scale ^yscale;

		System::Void button1_Click( System::Object^ , System::EventArgs^ );
	    System::Void button2_Click( System::Object^ , System::EventArgs^ );
		System::Void button3_Click( System::Object^  , System::EventArgs^ );
        
        double inputValue; 
		int XLENGTH = 25;
		double ts = 1;

		double yMax = 100;
		double yMin = -0.1;

		//This represent "ts" number of "step interval"
		double MINORXSTEP = 1;
		double MAJORXSTEP = 5;

		double minorYStep = 1;
		double majorYStep = 5; 
 
        double t = 0;

        double trackYMAX = 0;
		double trackYMIN = 0;



 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->zedGraphObj = (gcnew ZedGraph::ZedGraphControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->myTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->FileDialogA = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// zedGraphObj
			// 
			this->zedGraphObj->IsEnableHZoom = false;
			this->zedGraphObj->IsEnableVZoom = false;
			this->zedGraphObj->IsShowPointValues = true;
			this->zedGraphObj->Location = System::Drawing::Point(12, 12);
			this->zedGraphObj->Name = L"zedGraphObj";
			this->zedGraphObj->ScrollGrace = 0;
			this->zedGraphObj->ScrollMaxX = 0;
			this->zedGraphObj->ScrollMaxY = 0;
			this->zedGraphObj->ScrollMaxY2 = 0;
			this->zedGraphObj->ScrollMinX = 0;
			this->zedGraphObj->ScrollMinY = 0;
			this->zedGraphObj->ScrollMinY2 = 0;
			this->zedGraphObj->Size = System::Drawing::Size(1083, 547);
			this->zedGraphObj->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 574);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(449, 574);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Add Data Points";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(1009, 574);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 35);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(704, 586);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(91, 20);
			this->textBox1->TabIndex = 4;
			// 
			// FileDialogA
			// 
			this->FileDialogA->FileName = L"\"\"";
			this->FileDialogA->Filter = L"Text files (*.csv)|*.csv";
			this->FileDialogA->InitialDirectory = L"C:\\";
			this->FileDialogA->Title = L"Input Data";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(592, 589);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(677, 589);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"y =";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1120, 621);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphObj);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Main";
			this->Text = L"Graph";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
   
    };

}
