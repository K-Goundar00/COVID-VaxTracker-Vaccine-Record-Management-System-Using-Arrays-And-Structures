# include <iostream>
# include <fstream>
# include <string>

using namespace std;

//Function Prototypes

void introduces_the_program();

void repeating_instructions();

void exit_message();

void read_citizen_file(ifstream & file,struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],int & counter);

void display_citizen_file(ifstream & file,struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],int & counter);

void read_vaccine_file(ifstream & vaccine_file,struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[],int & counter);

void display_vaccine_file(ifstream & vaccine_file,struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[],int & counter);

void read_vaccination_file(ifstream & vaccination_file,struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[],int & counter);

void search_citizen(int search,ifstream & file,ifstream & vaccine_file,ifstream & vaccination_file, 
struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],
struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[], struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[], int & counter1,int & counter2 ,int & counter3);

void print_recommendation(ifstream & file,ifstream & vaccine_file,ifstream & vaccination_file, 
struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],
struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[], struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[], int & counter1,int & counter2 ,int & counter3);


string vaccine_name (int input);

void print_vaccination_data
(
ifstream & file,ifstream & vaccine_file,ifstream & vaccination_file, struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],
struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[], struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[], int & counter1, int & counter2, int & counter3);

struct citizen
{
	int id;	
	string fname;  
	string lname; 
	char gender;
	int age;
	int phone;	
	string address;
};

struct vaccination
{
	int c_id; 	
	int num_vac; 
	int v1_code;		
	int v1_date; 	
	int v2_code; 	
	int v2_date; 	
	int b_code; 		
	int b_date;
};

struct vaccine
{
	int vaccine_code;	
	string vaccine_name;
	int vaccine_minspace;
};


const int SIZE = 1000;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVENTEEN = 17;
const int EIGHTEEN = 18;
const int FIFTY_NINE = 59;
const int SIXTY = 60;
const int ZERO = 0;



int main ()
{
	//variable declaration

	int user_input = 0;
	int specific_search = 0;
	
	int citizen_counter = 0;
	int vaccination_counter = 0;
	int vaccine_counter = 0;

	string invalid; 	
	
	citizen c_id[SIZE];
	citizen c_fname[SIZE];  
	citizen c_lname[SIZE]; 
	citizen c_gender[SIZE];
	citizen c_age[SIZE];
	citizen c_phone[SIZE];	
	citizen c_address[SIZE];
	
	 
	vaccination v_c_id[SIZE]; 	
	vaccination v_num_vac[SIZE]; 
	vaccination v_v1_code[SIZE];		
	vaccination v_v1_date[SIZE]; 	
	vaccination v_v2_code[SIZE]; 	
	vaccination v_v2_date[SIZE]; 	
	vaccination v_b_code[SIZE]; 		
	vaccination v_b_date[SIZE];
	
 	
	vaccine vaccine_code[SIZE];	
	vaccine vaccine_name[SIZE];
	vaccine vaccine_minspace[SIZE];
	
	ifstream citizen_file;
	ifstream vaccination_file;
	ifstream vaccine_file;	
	
	//This will open all the txt files
	citizen_file.open("citizens.txt");
	vaccination_file.open("vaccination.txt");
	vaccine_file.open("vaccines.txt");
	
	introduces_the_program();	
	
	while (user_input != ONE)
	{
		cout<<"\n\tEnter option (1 - 6)"<<endl;
		cout<<"\t";
		cin>>user_input;
		cout<<endl;
		
		if (user_input == TWO)
		{
			//User calls the fuction to display contents of citizen file
			display_citizen_file(citizen_file,c_id,c_fname,c_lname,c_gender,c_age,c_phone,c_address,citizen_counter);
			repeating_instructions();
		}
		else if (user_input == THREE)
		{
			//User calls the fuction to display contents of vaccine file
			display_vaccine_file(vaccine_file,vaccine_code,vaccine_name,vaccine_minspace,vaccine_counter);
			repeating_instructions();
		}
		else if (user_input == FOUR)
		{
			//User calls the fuction to display contents of vaccination file
			print_vaccination_data(citizen_file,vaccine_file,vaccination_file,c_id,c_fname,c_lname,c_gender,c_age,c_phone,c_address,vaccine_code,vaccine_name,
			vaccine_minspace,v_c_id,v_num_vac,v_v1_code,v_v1_date,v_v2_code,v_v2_date,v_b_code,v_b_date,citizen_counter,vaccine_counter,vaccination_counter);
			repeating_instructions();	
		}
		
		else if (user_input == FIVE)
		{
			cout<<"\tPlease Enter Citizen Id."<<endl;
			cout<<"\t";
			string invalid;
			cin>>specific_search;
			
			if (cin.fail())
			{		
				cin.clear();
				cin>>invalid;
				cout<<"\tPlease Try Again"<<endl;
				repeating_instructions();
			}
			
			else if (specific_search <= ZERO)
			{		
				cout<<"\tPlease Try Again"<<endl;
				repeating_instructions();
			}
			
			else
			{
				search_citizen(specific_search,citizen_file,vaccine_file,vaccination_file,c_id,c_fname,c_lname,c_gender,c_age,c_phone,c_address,vaccine_code,vaccine_name,
				vaccine_minspace,v_c_id,v_num_vac,v_v1_code,v_v1_date,v_v2_code,v_v2_date,v_b_code,v_b_date,citizen_counter,vaccine_counter,vaccination_counter);
			}
		
		}
		
		else if (user_input == SIX)
		{
			print_recommendation(citizen_file,vaccine_file,vaccination_file,c_id,c_fname,c_lname,c_gender,c_age,c_phone,c_address,vaccine_code,vaccine_name,
			vaccine_minspace,v_c_id,v_num_vac,v_v1_code,v_v1_date,v_v2_code,v_v2_date,v_b_code,v_b_date,citizen_counter,vaccine_counter,vaccination_counter);
			repeating_instructions();
		
		}
		
		else if (cin.fail())
		{		
			cin.clear();
			cin>>invalid;
			cout<<"\tPlease Try Again"<<endl;
			repeating_instructions();
		
		}	
		
		else if (user_input <= ZERO)
		{	
			cout<<"\tPlease Try Again"<<endl;
			repeating_instructions();
			
		}

	}
	
	//Closes the txt file
	citizen_file.close();
	vaccine_file.close();
	vaccination_file.close();
	
	exit_message();
	
	return 0;
}

//Functions that introduces the program to the user and provides instructions
void introduces_the_program()
{
	cout<<"\t--------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n\t\t\t\tWelcome User\n"<<endl;
	cout<<"\tThis program will analyze the data to get meaningful insights which would "<<endl;
	cout<<"\tallow the Health Ministry to reach out to the people for vaccination, "<<endl;
	cout<<"\tvaccination drives, reports, and vaccination certificates for travels."<<endl;
	
	cout<<"\tHere are the services the program can provide."<<endl;


	repeating_instructions();
	
	
	cout<<"\t---------------------------------------------------------------------------------------------------------"<<endl;
}

//This function will repeat the services the program can provide
void repeating_instructions()
{
	cout<<"\n\tPress 1: To exit the program."<<endl;
	cout<<"\tPress 2: To print the citizens."<<endl;
	cout<<"\tPress 3: To print Vaccines."<<endl;
	cout<<"\tPress 4: To print vaccination data."<<endl;
	cout<<"\tPress 5: To search citizen using the Citizen ID."<<endl;
	cout<<"\tPress 6: To print recommendation.\n"<<endl;	
}



//This function will display the message once the user decides to exit the program
void exit_message()
{
	cout<<"\n\t\t\tHave A Good Day :) "<<endl;
}



//Function that will read data from citizen file.

void read_citizen_file(ifstream & citizen_file,struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],int & counter)
{
	
	
	string ignore_line;
	
	if (citizen_file.good())
	{
		while(!citizen_file.eof())
		{
			getline(citizen_file,ignore_line);
			citizen_file>>id[counter].id>>fname[counter].fname>>lname[counter].lname>>gender[counter].gender>>age[counter].age>>phone[counter].phone>>address[counter].address;
			counter++;
			
			
		}
	}
	
	else if (citizen_file.bad())
	{
		cout<<"Sorry File Does Not Exit."<<endl;
	}
	
		
	
}

//Function that will display data from citizen file

void display_citizen_file(ifstream & citizen_file,struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],int & counter)
{
	
	read_citizen_file(citizen_file,id,fname,lname,gender,age,phone,address,counter);
	
	cout<<"\tCID\t"<<"Fname"<<"\tLname"<<"\tGender"<<"\tAge"<<"\tPhone"<<"\t\tAddress"<<endl;
	cout<<"\t------------------------------------------------------------------------"<<endl;
	
	for(int i = 0; i < counter; i++)
	{
		cout<<"\t"<<id[i].id<<"\t"<<fname[i].fname<<"\t"<<lname[i].lname<<"\t  "<<
		gender[i].gender<<"\t"<<age[i].age<<"\t"<<phone[i].phone<<"\t\t"<<address[i].address<<endl;
		cout<<"\t------------------------------------------------------------------------"<<endl;
	}
	
	
}

//Function that will read data from vaccine file.

void read_vaccine_file(ifstream & vaccine_file,struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[],int & counter)
{
	string ignore_line;
	
	
	if (vaccine_file.good())
	{
		while(!vaccine_file.eof())
		{
			getline(vaccine_file,ignore_line);
			vaccine_file>>vaccine_code[counter].vaccine_code>>
			vaccine_name[counter].vaccine_name>>vaccine_minspace[counter].vaccine_minspace;
			counter++;
		}
	}
	
	else if (vaccine_file.bad()) 
	{
		cout<<"Sorry File Does Not Exit."<<endl;		
	}
}

// Function that display data from vaccine file

void display_vaccine_file(ifstream & vaccine_file,struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[],int & counter)
{
	read_vaccine_file(vaccine_file,vaccine_code,vaccine_name,vaccine_minspace,counter);
	
	
	cout<<"\tVaccine Code\t"<<"Vaccine Name"<<"\tVaccine Min Days"<<endl;
	cout<<"\t------------------------------------------------------------------------"<<endl;
	
		
	for(int i = 0; i < counter; i++)
	{
		cout<<"\t  "<<vaccine_code[i].vaccine_code<<"\t\t"<<vaccine_name[i].vaccine_name<<"\t\t"<<vaccine_minspace[i].vaccine_minspace<<endl;
		cout<<"\t------------------------------------------------------------------------"<<endl;
	}
	
	
}

//Function that will read data from vaccination file.

void read_vaccination_file(ifstream & vaccination_file, struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[],int & counter)
{
	string ignore_line;
	
	if (vaccination_file.good())
	{
		while(!vaccination_file.eof())
		{
			getline(vaccination_file,ignore_line);
			vaccination_file>>c_id[counter].c_id>>num_vac[counter].num_vac>>
			v1_code[counter].v1_code>>
			v1_date[counter].v1_date>>v2_code[counter].v2_code
			>>v2_date[counter].v2_date>>
			b_code[counter].b_code>>b_date[counter].b_date;
			counter++;
		
		}
		
	}
	
	else if (vaccination_file.bad())
	{
		cout<<"Sorry File Does Not Exit."<<endl;
	}

}

// Function that determine the type of vaccine 

string vaccine_display(int input)
{
	string vaccine;
	
	const int ONE = 5001;
	const int TWO = 5002;
	const int THREE = 5003;
	  
	if (input == ONE)
	{
		vaccine = "Pfizer_2.0";
	}
	
	else if (input == TWO)
	{
		vaccine = "Moderna1.0";
	}
	
	else if (input == THREE)
	{
		vaccine = "AstraZenca";
	}
	
	else 
	{
		vaccine = "        ";
	}
	
	return vaccine;
}

//Function that will print the vaccination data

void print_vaccination_data
(
ifstream & file,ifstream & vaccine_file,ifstream & vaccination_file, struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],
struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[], struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[], int & counter1,int & counter2 ,int & counter3)

{
	read_citizen_file(file,id,fname,lname,gender,age,phone,address,counter1);
	read_vaccine_file(vaccine_file,vaccine_code,vaccine_name,vaccine_minspace,counter2);
	read_vaccination_file(vaccination_file,c_id,num_vac,v1_code,v1_date,v2_code,v2_date,b_code,b_date,counter3);
	

	int v1;
	int v2;
	int b_1;
	string vaccine_1;
	string vaccine_2;
	string booster;
	
	
	cout<<"\tCID\t"<<"Full name"<<"\t#Vac"<<"\tV1 Name   "<<"\tV1 Date"<<"\t\tV2 Name"<<"\t\tV2 Date"<<"\t\tBooster Name"<<"\tBooster Date"<<endl;
	
	
	cout<<"\t---------------------------------------------------------------------------------------------------------------------------------"<<endl;
	
	for(int i = 0; i < counter3; i++)
	{
		for (int j = 0; j < counter1; j++)
		{
				if (c_id[i].c_id == id[j].id )
				{
						v1 = v1_code[i].v1_code;
						
						v2 = v2_code[i].v2_code;
						
						b_1 = b_code[i].b_code;
						
						vaccine_1 = vaccine_display(v1_code[i].v1_code);
						
						vaccine_2 = vaccine_display(v2_code[i].v2_code);
						
						booster = vaccine_display(b_code[i].b_code);
						
						cout<<"\t"<<id[j].id<<"\t"<<fname[j].fname<<" "<<lname[j].lname<<"\t"<<num_vac[i].num_vac<<"\t"<<vaccine_1<<"\t"
						<<v1_date[i].v1_date<<"\t"<<vaccine_2<<"\t"<<v2_date[i].v2_date<<"\t"<<booster<<"\t"<<b_date[i].b_date<<endl;
						cout<<"\t---------------------------------------------------------------------------------------------------------------------------------"<<endl;				}
				
		}

	}

}

void search_citizen(int search,ifstream & file,ifstream & vaccine_file,ifstream & vaccination_file, 
struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],
struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[], struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[], int & counter1,int & counter2 ,int & counter3)
{

	read_citizen_file(file,id,fname,lname,gender,age,phone,address,counter1);
	read_vaccine_file(vaccine_file,vaccine_code,vaccine_name,vaccine_minspace,counter2);
	read_vaccination_file(vaccination_file,c_id,num_vac,v1_code,v1_date,v2_code,v2_date,b_code,b_date,counter3);

	cout<<endl;
	
	for(int i = 0; i < counter1; i++)
	{
		if(id[i].id == search)
		{
			cout<<"\t--------------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t Citizen ID: "<<id[i].id<<endl<<endl;
			cout<<"\t Name: "<<fname[i].fname<<" "<<lname[i].lname;
			cout<<"\t Gender: ";
			
			if(gender[i].gender == 'M' || gender[i].gender == 'm' )
			{
				cout<<" Male"<<endl;
			}
			else
			{
				cout<<" Female"<<endl;
			}
			
			cout<<"\t Age: "<<age[i].age;
			cout<<"   \t\tPhone: "<<phone[i].phone<<endl;
			cout<<"\t Address: "<<address[i].address<<endl;
			cout<<"\t--------------------------------------------------------------------------------------"<<endl;
			cout<<endl;
			cout<<endl;
			
			{
				for(int j=0;j<counter3;j++)
			{
				if(c_id[j].c_id==search)
			{
				cout<<"\t--------------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t Vaccination Detail:"<<endl;
				cout<<"\t--------------------------------------------------------------------------------------"<<endl;
				cout<<"\tNumber of Vaccines: "<<num_vac[j].num_vac<<endl;
					
				for(int k = 0; k < num_vac[j].num_vac; k++)
				{
					if (k == TWO)
					{
						cout<<"\t\tBooster:\t";
						for(int l = 0; l < 3; l++)
						{
							if(vaccine_code[l].vaccine_code == b_code[j].b_code)
							{
								cout<<vaccine_name[l].vaccine_name<<"\t";
								cout<<"Booster Date: "<<b_date[j].b_date<<endl;
							}
							else if(vaccine_code[l].vaccine_code == b_code[j].b_code)
							{
								cout<<vaccine_name[l].vaccine_name<<"\t";
								cout<<"Booster Date: "<<b_date[j].b_date<<endl;
							}
							else if(vaccine_code[l].vaccine_code == b_code[j].b_code)
							{
								cout<<vaccine_name[l].vaccine_name<<"\t";
								cout<<"Booster Date: "<<b_date[j].b_date<<endl;
							}
						}
					}
						else if(k == ONE)
						{
							cout<<"\tVaccination "<< k + 1 <<": ";
							for(int l = 0; l<counter2; l++)
							{
								if(vaccine_code[l].vaccine_code == v2_code[j].v2_code)
								{
									cout<<vaccine_name[l].vaccine_name<<"\t";
									cout<<"Vaccination Date: "<<v2_date[j].v2_date<<endl;
								}
								else if(vaccine_code[l].vaccine_code == v2_code[j].v2_code)
								{
									cout<<vaccine_name[l].vaccine_name<<"\t";
									cout<<"Vaccination Date: "<<v2_date[j].v2_date<<endl;
								}
								else if(vaccine_code[l].vaccine_code == v2_code[j].v2_code)
								{
									cout<<vaccine_name[l].vaccine_name<<"\t";
									cout<<"Vaccination Date: "<<v2_date[j].v2_date<<endl;
								}
							}
						}
						else if(k == ZERO)
						{
							cout<<"\tVaccination "<<k+1<<": ";
							for(int l=0;l<counter3;l++)
							{
								if(vaccine_code[l].vaccine_code == v1_code[j].v1_code)
								{
									cout<<vaccine_name[l].vaccine_name<<"\t";
									cout<<"Vaccination Date: "<<v1_date[j].v1_date<<endl;
								}
								else if(vaccine_code[l].vaccine_code == v1_code[j].v1_code)
								{
									cout<<vaccine_name[l].vaccine_name<<"\t";
									cout<<"Vaccination Date: "<<v1_date[j].v1_date<<endl;
								}
								else if(vaccine_code[l].vaccine_code == v1_code[j].v1_code)
								{
									cout<<vaccine_name[l].vaccine_name<<"\t";
									cout<<"Vaccination Date: "<<v1_date[j].v1_date<<endl;
								}
							}
						}
					}
					if(num_vac[j].num_vac == ONE)
					{
						cout<<"\n\tVaccinated Status: Partially Vaccinated"<<endl; 
					}
					else if(num_vac[j].num_vac == TWO)
					{
						cout<<"\n\tVaccinated Status: Fully Vaccinated "<<endl;
					}
					else
					{
						cout<<"\n\tVaccinated Status: Fully Vaccinated with Booster"<<endl;
					}
					cout<<"\t--------------------------------------------------------------------------------------"<<endl;
				}
			}
			}
		}
	}
};

void print_recommendation(ifstream & file,ifstream & vaccine_file,ifstream & vaccination_file, 
struct citizen id[],struct citizen fname[],struct citizen lname[],struct citizen gender[],
struct citizen age[],struct citizen phone[],struct citizen address[],
struct vaccine vaccine_code[],struct vaccine vaccine_name[],struct vaccine vaccine_minspace[], struct vaccination c_id[],
struct vaccination num_vac[],struct vaccination v1_code[],struct vaccination v1_date[],struct vaccination v2_code[],
struct vaccination v2_date[],struct vaccination b_code[],struct vaccination b_date[], int & counter1,int & counter2 ,int & counter3)

{
	read_citizen_file(file,id,fname,lname,gender,age,phone,address,counter1);
	read_vaccine_file(vaccine_file,vaccine_code,vaccine_name,vaccine_minspace,counter2);
	read_vaccination_file(vaccination_file,c_id,num_vac,v1_code,v1_date,v2_code,v2_date,b_code,b_date,counter3);
	
	
	const int C = 16793183;
	int N = 0;
	
	
	cout<<"\tC ID\tFull Name\t       #Vac\tVaccination Status\t\t\tRecommendation"<<endl;
	
	for (int i = 0; i < counter3; i++)
     	{
     		cout<<"\t------------------------------------------------------------------------------------------------------------------------"<<endl;
     		cout<<"\t"<<c_id[i].c_id<<"\t";
     		
     		for(int j=0; j < counter3; j++)
     		{
     			if(id[j].id==c_id[i].c_id)
     			{
     				cout<<fname[j].fname<<" "<<lname[j].lname;
     				cout<<"\t\t"<<num_vac[i].num_vac<<"\t";
				}
				
			}
			
			
			if(num_vac[i].num_vac == ONE)
					{
						cout<<"Partially Vaccinated\t\t"; 
					}
					else if(num_vac[i].num_vac == TWO)
					{
						cout<<"Fully Vaccinated\t\t";
					}
					else if(num_vac[i].num_vac == THREE)
					{
						cout<<"Fully Vaccinated with Booster\t\t";
					}
					//Coding for recommendation
					
			for(int j = 0; j<counter1; j++)
     		{
     			if(id[j].id == c_id[i].c_id)
     			{
     				if(age[j].age <= FIVE || age[j].age >= SIXTY)
     				{
     					if(num_vac[i].num_vac == 1)
     					{
     						int N = C - v1_date[i].v1_date;
     						
     						for(int k = 0; k<counter3; k++)
     						{
     							if(v1_code[i].v1_code == vaccine_code[k].vaccine_code)
     							{
     								if(N<vaccine_minspace[k].vaccine_minspace)
     								{
     									cout<<"\t"<<N<<"number of days left for second shot."<<endl;
									}
									else
									{
										cout<<"\tReady for second vaccine: Pfizer"<<endl;
									}
								}
							}
						}
						else if(num_vac[i].num_vac == TWO)
						{
							cout<<"\tFully Vaccinated. Booster is not needed."<<endl;
						}
					}
					else if(age[j].age >= SIX&&age[j].age <= SEVENTEEN)
					{
						if(num_vac[i].num_vac == THREE)
     					{
							cout<<"\tFully Vaccinated with Booster\t\t"<<endl;
						}
						else if (num_vac[i].num_vac == TWO)
						{
							int N = C - v1_date[i].v1_date;
     						for(int k = 0; k < counter2 ;k++)
     						{
     							if(v1_code[i].v1_code == vaccine_code[k].vaccine_code)
     							{
     								if(N < vaccine_minspace[k].vaccine_minspace && N<vaccine_minspace[k].vaccine_minspace)
     								{
     									cout<<"\t"<<N<<"number of days left for Booster shot."<<endl;
									}
									else if(N > vaccine_minspace[k].vaccine_minspace && N>vaccine_minspace[k].vaccine_minspace)
									{
										cout<<"\tReady for Booster: Pfizer"<<endl;
									}
								}
							}
						}
						else
						{
							int N = C - v1_date[i].v1_date;
							
     						for(int k = 0; k < counter2; k++)
     						{
     							if(v1_code[i].v1_code == vaccine_code[k].vaccine_code)
     							{
     								if(N < vaccine_minspace[k].vaccine_minspace)
     								{
     									cout<<"\t"<<N<<"number of days left for second shot."<<endl;
									}
									else
									{
										cout<<"\tReady for second vaccine: Moderna"<<endl;
									}
								}
							}
						}
					}
					else if(age[j].age >= EIGHTEEN&&age[j].age <= FIFTY_NINE)
					{
						if(num_vac[i].num_vac == ONE)
     					{
     						int N = C - v1_date[i].v1_date;
     						for(int k = 0; k < counter3; k++)
     						{
     							if(v1_code[i].v1_code == vaccine_code[k].vaccine_code)
     							{
     								if(N < vaccine_minspace[k].vaccine_minspace)
     								{
     									cout<<"\t"<<N<<"number of days left for second shot."<<endl;
									}
									else
									{
										cout<<"\tReady for second vaccine: AstraZeneca"<<endl;
									}
								}
							}
						}
						else if(num_vac[i].num_vac == TWO)
						{
							int N = C-v1_date[i].v1_date;
							
     						for(int k = 0; k<counter3; k++)
     						{
     							if(v1_code[i].v1_code == vaccine_code[k].vaccine_code)
     							{
     								if(N < vaccine_minspace[k].vaccine_minspace && N < vaccine_minspace[k].vaccine_minspace)
     								{
     									cout<<N<<" number of days left for Booster shot."<<endl;
									}
									else if(N > vaccine_minspace[k].vaccine_minspace && N > vaccine_minspace[k].vaccine_minspace)
									{
										cout<<"\tReady for Booster: Pfizer"<<endl;
									}
								}
							}
						}
						else
						{
							cout<<"Fully Vaccinated with Booster\t"<<endl;
						}
					}
				}
			}
				
		}
	
};
