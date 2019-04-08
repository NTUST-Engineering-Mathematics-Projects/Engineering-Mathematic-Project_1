#pragma once
#include"DotNetUtilities.h"
#include"InfixToPostfix.h"

namespace WindowsFormsApplication_cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm ���K�n
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			lastInputLength = -1;
			// Vector = 0, Matrix = 1, Mode
			Vector_Or_Matrix = 0;
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;





	private: System::Windows::Forms::Label^  OutputLabel;
	private: System::Windows::Forms::TextBox^  Output;

	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;





	protected:


	protected:

	private:
		/// <summary>
			DataManager* dataManager;
			String^ userInput;
			int lastInputLength;
			int Vector_Or_Matrix;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  VectorLabel;
	private: System::Windows::Forms::ListBox^  VectorList;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->InputLabel = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->OutputLabel = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->VectorLabel = (gcnew System::Windows::Forms::Label());
			this->VectorList = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(36, 36);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(14, 4, 0, 4);
			this->menuStrip2->Size = System::Drawing::Size(1588, 47);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->LoadVectorToolStripMenuItem });
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(70, 39);
			this->FileToolStripMenuItem->Text = L"File";
			// 
			// LoadVectorToolStripMenuItem
			// 
			this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(395, 42);
			this->LoadVectorToolStripMenuItem->Text = L"Load Vector or Matrix";
			this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->VectorLabel, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->VectorList, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->Input, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->Output, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 47);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(7);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1588, 1151);
			this->tableLayoutPanel1->TabIndex = 2;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &WindowsForm::tableLayoutPanel1_Paint);
			// 
			// InputLabel
			// 
			this->InputLabel->AutoSize = true;
			this->InputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->InputLabel->Location = System::Drawing::Point(7, 0);
			this->InputLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->InputLabel->Name = L"InputLabel";
			this->InputLabel->Size = System::Drawing::Size(84, 35);
			this->InputLabel->TabIndex = 0;
			this->InputLabel->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Input->Location = System::Drawing::Point(7, 445);
			this->Input->Margin = System::Windows::Forms::Padding(7);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(1574, 324);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged_Vector);
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged_Matrix);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->OutputLabel, 0, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.03209F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(1507, 41);
			this->tableLayoutPanel3->TabIndex = 5;
			// 
			// OutputLabel
			// 
			this->OutputLabel->AutoSize = true;
			this->OutputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->OutputLabel->Location = System::Drawing::Point(7, 0);
			this->OutputLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->OutputLabel->Name = L"OutputLabel";
			this->OutputLabel->Size = System::Drawing::Size(108, 35);
			this->OutputLabel->TabIndex = 0;
			this->OutputLabel->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Output->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Output->Location = System::Drawing::Point(7, 54);
			this->Output->Margin = System::Windows::Forms::Padding(7);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Output->Size = System::Drawing::Size(1574, 324);
			this->Output->TabIndex = 1;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->InputLabel, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 388);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.56684F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(1560, 47);
			this->tableLayoutPanel4->TabIndex = 6;
			// 
			// VectorLabel
			// 
			this->VectorLabel->AutoSize = true;
			this->VectorLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->VectorLabel->Location = System::Drawing::Point(7, 776);
			this->VectorLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->VectorLabel->Name = L"VectorLabel";
			this->VectorLabel->Size = System::Drawing::Size(227, 35);
			this->VectorLabel->TabIndex = 4;
			this->VectorLabel->Text = L"Vector or Matrix";
			this->VectorLabel->Click += gcnew System::EventHandler(this, &WindowsForm::VectorLabel_Click);
			// 
			// VectorList
			// 
			this->VectorList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VectorList->FormattingEnabled = true;
			this->VectorList->ItemHeight = 27;
			this->VectorList->Location = System::Drawing::Point(7, 818);
			this->VectorList->Margin = System::Windows::Forms::Padding(7);
			this->VectorList->Name = L"VectorList";
			this->VectorList->Size = System::Drawing::Size(1574, 326);
			this->VectorList->TabIndex = 5;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			// 
			// WindowsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 27);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1588, 1198);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Margin = System::Windows::Forms::Padding(7);
			this->Name = L"WindowsForm";
			this->Text = L"Project1";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//�}��Dialog
	openFileDialog1->ShowDialog();
}
// Vector Input
private: System::Void Input_TextChanged_Vector(System::Object^  sender, System::EventArgs^  e)
{
	//��Input textbox������J���ܮɡA�K�|�i�J���禡
	if (Vector_Or_Matrix)
		return;
	//���o�V�q���
	std::vector<Vector> vectors = dataManager->GetVectors();
	//�P�_��J�ۤ���'\n'�A�è������r��-1��m
	if (Input->Text->Length-1 >= 0 &&Input->Text[Input->Text->Length - 1] == '\n')
	{
		//�N�ϥΪ̿�J�r��(�buserInput��)�A�̪ťէ@����
		array<String^> ^userCommand = userInput->Split(' ');
		//�r�����A�Y���O��"print"�����p
		try
		{
			if (userCommand[0] == "print")
			{
				//�w�N��X�Ȧs
				String^ outputTemp = "";
				std::string temp;
				MarshalString(userCommand[1], temp);
				int Printflag = 0; //�䤣�쪺�V�q�ίx�}(0 ���S�����V�q�ίx�})
				if (temp[0] == '$' && temp[1] == 'v')
				{
					//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[1] == gcnew String(vectors[i].Name.c_str()))
						{
							Printflag = 1;
							//�N��X�榡�s�J�Ȧs
							outputTemp += "[";
							//�N��X��Ʀs�J�Ȧs
							for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
							{
								outputTemp += vectors[i].Data[j].ToString();
								if (j != vectors[i].Data.size() - 1)
									outputTemp += ",";
							}
							//�N��X�榡�s�J�Ȧs�A�åB����
							outputTemp += "]" + Environment::NewLine;
							//��X�Ȧs��T
							Output->Text += gcnew String(vectors[i].Name.c_str()) + " = " + outputTemp;
							break;
						}
					}
					// ���~����
					if (!Printflag)
					{
						Output->Text += "There is no such vector�I" + Environment::NewLine;
					}
				}
				// ���~����
				else
				{
					Output->Text += "-Command not found-" + Environment::NewLine;
				}
			}
			// Clear Output, Input TextBox
			else if (userCommand[0] == "clear")
			{
				Output->Clear();
				Input->Clear();
			}
			//�i��p��
			else if (userCommand[0] == "calV")
			{
				// �榡�GA dot B => $v1 * $v2 (dot��scalar���i�H��*)
				std::vector<std::string>userinput;
				for (unsigned int i = 1; i < userCommand->Length; i++)
				{
					std::string temp;
					MarshalString(userCommand[i], temp);
					userinput.push_back(temp);
				}
				InfToPos(userinput);
				std::vector<Vector>VStack;
				Vector CalAns;
				for (unsigned int i = 0; i < userinput.size(); i++)
				{
					int operation = -1;
					if (userinput[i] == "+")
						operation = 1;
					else if (userinput[i] == "-")
						operation = 2;
					else if (userinput[i] == "*" || userinput[i] == "dot")
						operation = 3;
					else
					{
						bool HasVector = false;
						for (unsigned int j = 0; j < vectors.size(); j++)
						{
							if (userinput[i] == vectors[j].Name)
							{
								VStack.push_back(vectors[i]);
								HasVector = true;
								break;
							}
						}
						if (!HasVector)
						{
							// Vector Error
						}
						continue;
					}
					Vector Ans = VStack[VStack.size() - 1];
					VStack.pop_back();
					switch (operation)
					{
					case 1:
						VStack[VStack.size() - 1] = VStack[VStack.size() - 1] + Ans;
						break;
					case 2:
						VStack[VStack.size() - 1] = VStack[VStack.size() - 1] - Ans;
						break;
					case 3:
						VStack[VStack.size() - 1] = VStack[VStack.size() - 1] * Ans;
						break;
					}
					CalAns = VStack[VStack.size() - 1];
				}
				String^ outputTemp = "Answer is�G[" + Environment::NewLine;
				for (unsigned int i = 0; i < CalAns.Data.size(); i++)
				{
					outputTemp += CalAns.Data[i].ToString();
					if (i != CalAns.Data.size() - 1)
						outputTemp += ",";
				}
				outputTemp += "]" + Environment::NewLine;
				Output->Text += outputTemp;
			}
			//�Ϥ��h�P�_�䤣����O
			else
			{
				Output->Text += "-Command not found-" + Environment::NewLine;
			}
		}
		// Matrix Error Handle
		catch(Vector_Error Err) {
			switch (Err)
			{
			default:
				Output->Text += "Vector Error�I";
				break;
			}
			Output->Text += Environment::NewLine;
		}
		userInput = "";
	}
	else
	{
		//�N�ϥΪ̿�J�r��(�bText box��)�A��'\n'�@����
		array<String^> ^userCommand = Input->Text->Split('\n');
		//�ñN�̫�@��A�@���ثe�ϥΪ̿�J���O
		userInput = userCommand[userCommand->Length-1];
	}

}

private: System::Void Input_TextChanged_Matrix(System::Object^  sender, System::EventArgs^  e)
{
	if (!Vector_Or_Matrix)
		return;
	//��Input textbox������J���ܮɡA�K�|�i�J���禡
	//���o�x�}���
	std::vector<Matrix> matrixs = dataManager->GetMatrixs();
	//�P�_��J�ۤ���'\n'�A�è������r��-1��m
	if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
	{
		//�N�ϥΪ̿�J�r��(�buserInput��)�A�̪ťէ@����
		array<String^> ^userCommand = userInput->Split(' ');
		//�r�����A�Y���O��"print"�����p
		try
		{
			if (userCommand[0] == "print")
			{
				//�w�N��X�Ȧs
				String^ outputTemp = "";
				std::string temp;
				MarshalString(userCommand[1], temp);
				int Printflag = 0; //�䤣�쪺�V�q�ίx�}(0 ���S�����V�q�ίx�})
				if (temp[0] == '$' && temp[1] == 'm')
				{
					// Print Matrix
					for (unsigned int i = 0; i < matrixs.size(); i++)
					{
						if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
						{
							Printflag = 1;
							outputTemp += "[" + Environment::NewLine;
							for (unsigned int j = 0; j < matrixs[i].Data.size(); j++)
							{
								for (unsigned int k = 0; k < matrixs[i].Data[j].size(); k++)
								{
									outputTemp += matrixs[i].Data[j][k].ToString();
									if (k != matrixs[i].Data[j].size() - 1)
										outputTemp += ",";
								}
								outputTemp += Environment::NewLine;
							}
							outputTemp += "]" + Environment::NewLine;
							Output->Text += gcnew String(matrixs[i].Name.c_str()) + " = " + outputTemp;
							break;
						}
					}
					// ���~����
					if (!Printflag)
					{
						Output->Text += "There is no such Matrix�I" + Environment::NewLine;
					}
				}
				// ���~����
				else
				{
					Output->Text += "-Command not found-" + Environment::NewLine;
				}
			}
			// Clear Output, Input TextBox
			else if (userCommand[0] == "clear")
			{
				Output->Clear();
				Input->Clear();
			}
			//�i��p��
			else if (userCommand[0] == "calM")
			{
				// �榡�GA * B => $m1 * $m2 (scalar�i�H��*)
				std::vector<std::string>userinput;
				for (unsigned int i = 1; i < userCommand->Length; i++)
				{
					std::string temp;
					MarshalString(userCommand[i], temp);
					userinput.push_back(temp);
				}
				InfToPos(userinput);
				std::vector<Matrix>MStack;
				Matrix CalAns;
				for (unsigned int i = 0; i < userinput.size(); i++)
				{
					int operation = -1;
					if (userinput[i] == "+")
						operation = 1;
					else if (userinput[i] == "-")
						operation = 2;
					else if (userinput[i] == "*" || userinput[i] == "dot")
						operation = 3;
					else
					{
						bool HasMatrix = false;
						for (unsigned int j = 0; j < matrixs.size(); j++)
						{
							if (userinput[i] == matrixs[j].Name)
							{
								MStack.push_back(matrixs[i]);
								HasMatrix = true;
								break;
							}
						}
						if (!HasMatrix)
						{
							throw Matrix_Error::Has_No_Such_Matrix;
						}
						continue;
					}
					Matrix Ans = MStack[MStack.size() - 1];
					MStack.pop_back();
					switch (operation)
					{
					case 1:
						MStack[MStack.size() - 1] = MStack[MStack.size() - 1] + Ans;
						break;
					case 2:
						MStack[MStack.size() - 1] = MStack[MStack.size() - 1] - Ans;
						break;
					case 3:
						MStack[MStack.size() - 1] = MStack[MStack.size() - 1] * Ans;
						break;
					}
					CalAns = MStack[MStack.size() - 1];
				}
				String^ outputTemp = "Answer is�G[" + Environment::NewLine;
				for (unsigned int i = 0; i < CalAns.row(); i++)
				{
					for (unsigned int j = 0; j < CalAns.column(); j++)
					{
						outputTemp += CalAns.Data[i][j].ToString();
						if (j != CalAns.column() - 1)
							outputTemp += ",";
					}
					outputTemp += Environment::NewLine;
				}
				outputTemp += "]" + Environment::NewLine;
				Output->Text += outputTemp;
			}
			else if (userCommand[0] == "rank")
			{
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						Output->Text += "Rank of " + userCommand[1] + " = " + matrixs[i].Rank() + Environment::NewLine;
						break;
					}
				}
			}
			else if (userCommand[0] == "det")
			{
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						try {
							if (matrixs[i].Data.size() == matrixs[i].Data[0].size())
								throw matrixs[i].Determinant();
							else
								throw "Error�GRow != Column";
						}
						catch (double Det)
						{
							Output->Text += "Determinant of " + userCommand[1] + " = " + Det + Environment::NewLine;
						}
						catch (std::string Err)
						{
							Output->Text += gcnew String(Err.c_str()) + Environment::NewLine;
						}
						break;
					}
				}
			}
			else if (userCommand[0] == "Inv")
			{
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						Matrix IsEqual = matrixs[i].Inverse();
						Output->Text += "Inverse�G[" + Environment::NewLine;
						String^ outputTemp = "";
						// Print Inverse Matrix
						for (unsigned int j = 0; j < IsEqual.Data.size(); j++)
						{
							for (unsigned int k = 0; k < IsEqual.Data[0].size(); k++)
							{
								outputTemp += IsEqual.Data[j][k].ToString();
								if (k != IsEqual.Data[j].size() - 1)
									outputTemp += ",";
							}
							outputTemp += Environment::NewLine;
						}
						outputTemp += "]" + Environment::NewLine;
						Output->Text += gcnew String(matrixs[i].Name.c_str()) + " = " + outputTemp;
						break;
					}
				}
			}
			else if (userCommand[0] == "Adj")
			{
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						Matrix IsEqual = matrixs[i].Adjoint();
						Output->Text += "Adjoint�G[" + Environment::NewLine;
						String^ outputTemp = "";
						// Print Adjoint Matrix
						for (unsigned int j = 0; j < IsEqual.Data.size(); j++)
						{
							for (unsigned int k = 0; k < IsEqual.Data[0].size(); k++)
							{
								outputTemp += IsEqual.Data[j][k].ToString();
								if (k != IsEqual.Data[j].size() - 1)
									outputTemp += ",";
							}
							outputTemp += Environment::NewLine;
						}
						outputTemp += "]" + Environment::NewLine;
						Output->Text += gcnew String(matrixs[i].Name.c_str()) + " = " + outputTemp;
						break;
					}
				}
			}
			else if (userCommand[0] == "Solve")
			{
				Matrix sm1, sm2;
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						sm1 = matrixs[i];
						break;
					}
				}
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{

					if (userCommand[2] == gcnew String(matrixs[i].Name.c_str()))
					{
						sm2 = matrixs[i];
						break;
					}
				}
				sm1 = sm1.Solve(sm2);
				Output->Text += "Answer�G[" + Environment::NewLine;
				String^ outputTemp = "";
				// Print Answer Matrix
				for (unsigned int i = 0; i < sm1.row(); i++)
				{
					for (unsigned int j = 0; j < sm1.column(); j++)
					{
						outputTemp += sm1.Data[i][j].ToString();
						if (j != sm1.column() - 1)
							outputTemp += ",";
					}
					outputTemp += Environment::NewLine;
				}
				outputTemp += "]" + Environment::NewLine;
				Output->Text += outputTemp;
			}
			else if (userCommand[0] == "LeastSquare")
			{
				Matrix sm1, sm2;
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						sm1 = matrixs[i];
						break;
					}
				}
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{

					if (userCommand[2] == gcnew String(matrixs[i].Name.c_str()))
					{
						sm2 = matrixs[i];
						break;
					}
				}
				sm1 = sm1.LeastSquare(sm2);
				Output->Text += "Answer�G[" + Environment::NewLine;
				String^ outputTemp = "";
				// Print Answer Matrix
				for (unsigned int i = 0; i < sm1.row(); i++)
				{
					for (unsigned int j = 0; j < sm1.column(); j++)
					{
						outputTemp += sm1.Data[i][j].ToString();
						if (j != sm1.column() - 1)
							outputTemp += ",";
					}
					outputTemp += Environment::NewLine;
				}
				outputTemp += "]" + Environment::NewLine;
				Output->Text += outputTemp;
			}
			else if (userCommand[0] == "Eigen")
			{
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						std::vector<Matrix>Ans = matrixs[i].Eigen();
						String^ outputTemp = "";
						// Print Answer Matrixs
						for (unsigned int j = 0; j < Ans.size(); j++)
						{
							if (!j)
							{
								outputTemp += "EigenValue�G" + Environment::NewLine;
							}
							else
							{
								outputTemp += "EigenVector�G" + Environment::NewLine;
							}
							for (unsigned int k = 0; k < Ans[j].column(); k++)
							{
								for (unsigned int l = 0; l < Ans[j].row(); l++)
								{
									outputTemp += Ans[j].Data[l][k].ToString();
									if (l != Ans[j].column() - 1)
										outputTemp += "  ";
								}
								outputTemp += Environment::NewLine;
							}
						}
						Output->Text += gcnew String(matrixs[i].Name.c_str()) + " = " + outputTemp;
						break;
					}
				}
			}
			else if (userCommand[0] == "PM")
			{
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					if (userCommand[1] == gcnew String(matrixs[i].Name.c_str()))
					{
						std::vector<Matrix>Ans = matrixs[i].PM();
						String^ outputTemp = "";
						// Print Answer Matrixs
						for (unsigned int j = 0; j < Ans.size(); j++)
						{
							if (!j)
							{
								outputTemp += "EigenValue�G" + Environment::NewLine;
							}
							else
							{
								outputTemp += "EigenVector�G" + Environment::NewLine;
							}
							for (unsigned int k = 0; k < Ans[j].column(); k++)
							{
								for (unsigned int l = 0; l < Ans[j].row(); l++)
								{
									outputTemp += Ans[j].Data[l][k].ToString();
									if (l != Ans[j].row() - 1)
										outputTemp += "  ";
								}
								outputTemp += Environment::NewLine;
							}
						}
						Output->Text += gcnew String(matrixs[i].Name.c_str()) + " = " + outputTemp;
						break;
					}
				}
			}
			//�Ϥ��h�P�_�䤣����O
			else
			{
				Output->Text += "-Command not found-" + Environment::NewLine;
			}
		}
		// Matrix Error Handle
		catch (Matrix_Error Err) {
			switch (Err)
			{
			case Matrix_Error::Dimension_Error:
				Output->Text += "Dimension_Error";
				break;
			case Matrix_Error::Row_And_Column_NotEqual:
				Output->Text += "Row_And_Column_NotEqual";
			case Matrix_Error::Rank_Not_Equal_To_Row:
				Output->Text += "Row > Rank�I�I";
				break;
			case Matrix_Error::Determinant_Is_Zero:
				Output->Text += "Determinant = 0";
				break;
			case Matrix_Error::Can_Not_Solve:
				Output->Text += "Row_And_Column_NotEqual, Can_Not_Solve";
				break;
			case Matrix_Error::Has_No_Such_Matrix:
				Output->Text += "There_Is_No_Such_Matrix";
				break;
			case Matrix_Error::Matrix_Size_Out_of_Range:
				Output->Text += "Matrix's Row > 3";
				break;
			default:
				Output->Text += "Matrix Error";
				break;
			}
			Output->Text += Environment::NewLine;
		}
		userInput = "";
	}
	else
	{
		//�N�ϥΪ̿�J�r��(�bText box��)�A��'\n'�@����
		array<String^> ^userCommand = Input->Text->Split('\n');
		//�ñN�̫�@��A�@���ثe�ϥΪ̿�J���O
		userInput = userCommand[userCommand->Length - 1];
	}

}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	//�bDialog���UOK�K�|�i�J���禡
	//�r�����string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//�N�ɮ׸��|�W�ٶǤJdataManager
	dataManager->SetFileName(tempFileName);
	//�qŪ��Ū���V�q���
	if (dataManager->ReadFileName())
	{
		if (!dataManager->VM)
		{
			Vector_Or_Matrix = 0;
			//�NVectorList�����إ����M��
			VectorList->Items->Clear();
			//���o�Ҧ��V�q���
			std::vector<Vector> vectors = dataManager->GetVectors();

			for (unsigned int i = 0; i < vectors.size(); i++)
			{
				//�N�ɮצW�٦s�J�Ȧs
				std::string tempString = vectors[i].Name;
				//�N��X�榡�s�J�Ȧs
				tempString += " [";
				//�N��X��Ʀs�J�Ȧs
				for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[i].Data[j]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (j != vectors[i].Data.size() - 1)
						tempString += ",";
				}
				//�N��X�榡�s�J�Ȧs
				tempString += "]";
				//�N���إ[�JVectorList��
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
		}
		else
		{
			Vector_Or_Matrix = 1;
			//�NMatrixList�����إ����M��
			VectorList->Items->Clear();
			//���o�Ҧ��x�}���
			std::vector<Matrix> matrixs = dataManager->GetMatrixs();

			for (unsigned int i = 0; i < matrixs.size(); i++)
			{
				//�N�ɮצW�٦s�J�Ȧs
				std::string tempString = matrixs[i].Name;
				//�N��X�榡�s�J�Ȧs
				tempString += "[";
				VectorList->Items->Add(gcnew String(tempString.c_str()) + Environment::NewLine);
				tempString.clear();
				//�N��X��Ʀs�J�Ȧs
				//Rows
				for (unsigned int j = 0; j < matrixs[i].Data.size(); j++)
				{
					//Columns
					for (unsigned int k = 0; k < matrixs[i].Data[j].size(); k++)
					{
						std::string scalarString = std::to_string(matrixs[i].Data[j][k]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if (k != matrixs[i].Data[j].size() - 1)
							tempString += ", ";
					}
					VectorList->Items->Add(gcnew String(tempString.c_str()) + Environment::NewLine);
					tempString.clear();
				}
				//�N��X�榡�s�J�Ȧs
				tempString += "]";
				//�N���إ[�JVectorList��
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
		}
	}
	else
	{
		Output->Text += "File Not Found�I�I�I" + Environment::NewLine;
	}
}
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void VectorLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}