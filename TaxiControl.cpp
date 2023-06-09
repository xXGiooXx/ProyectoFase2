#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include<fstream>
#include <sstream>
#include <cctype>
#include "Textable.h"
#include "Funciones.h"


using namespace std;

bool checkForItemInt(vector<int> arr, int data);
bool checkForItemInt(vector<string> arr, string data);
void printTable(vector<int> taxis, vector<string> driversName, vector<string> driversLastname, vector<int> driversId, vector<string>insuranceNumbers, vector<int> phoneNumbers, vector<string> modelNames, vector<int> years, vector<string> motorNumbers, vector<string> plates, vector<string> categories); //EN ESTA FUNCION SE MANDAND TODOS LOS ARREGLOS(VECTORES) A IMPRIMIR
VerificationData v;

int main(){
	char response='\0';
	int option;
	int id;
	int idtaxi;
	char confirmation;
	int idToReinsert; 
	string starting_place, destination_place, date;
	double cost; 
/////////////////////////////////////DRIVER DATA //////////////////////////////////////////////////	
	string driverName;
	string driverLastname; 
	string insuranceNumber; 
	int driverId; 
	int phoneNumber; 
///////////////////////////////////////CAR DATA////////////////////////////////////////////////////	
	string plateNumber;
	string modelName; 
	string motorNumber;
	string taxiCategory;
	int year;	
	cout<<"Taxi queue system\t\n";
	vector<int> taxis;
	vector<int> years; 
	vector<int> driversId; 
	vector<int> phoneNumbers; 
	vector<string> driversName;
	vector<string> driversLastname; 
	vector<string> insuranceNumbers; 
	vector<string> plates;
	vector<string> modelNames; 
	vector<string> motorNumbers; 
	vector<string> categories; 
//////////////////////////////////////////ROUTE CHECKS DATA////////////////////////////////////////
	vector<int> nAtaxis; 
	vector<int> nAyears; 
	vector<int> nAdriversId;
	vector<int> nAphoneNumbers; 
	vector<string> nAdriversName;
	vector<string> nAdriversLastname;        
	vector<string> nAinsuranceNumbers; 
	vector<string> nAplates; 
	vector<string> nAmodelNames; 
	vector<string> nAmotorNumbers; 
	vector<string> nAcategories;   
	
	vector<string> nAdates;
	vector<string> nAstart_times;
	vector<string> nAend_times;
	vector<string> nAstarting_places; 
	vector<string> nAdestination_places; 
	vector<double> nAcosts;
	vector<string> dateAndTime;
///////////////////////////////////////////TRAVEL DATA//////////////////////////////////////////////////////
vector<int> tr_taxis; 
vector<string> tr_driversName;
vector<string> tr_driversLastname;
vector<int> tr_driversId;
vector<string> tr_modelNames;
vector<int> tr_years; 
vector<string> tr_categories; 
vector<string> tr_dates; 
vector<string> tr_start_times;
vector<string> tr_end_times; 
vector<string> tr_starting_places;
vector<string> tr_destination_places;
vector<double> tr_costs;
/////////////////////////////////////////////////////////////////////////////////////////////////
loadOnRoutedataFromFile(nAtaxis, nAdriversName, nAdriversLastname, nAdriversId, nAinsuranceNumbers, nAphoneNumbers,
                            nAmodelNames, nAyears, nAmotorNumbers, nAplates, nAcategories, nAdates, nAstart_times, nAstarting_places, nAdestination_places, nAcosts);
                            
loadCardataFromFile(taxis, driversName, driversLastname, driversId, insuranceNumbers, phoneNumbers,
                            modelNames, years, motorNumbers, plates, categories);

loadTravelDataFromFile(tr_taxis, tr_driversName, tr_driversLastname, tr_driversId, tr_modelNames, tr_years, tr_categories, tr_dates, 
					   tr_start_times, tr_end_times, tr_starting_places, tr_destination_places, tr_costs);
////////////////////////////////////////////////////////////////////////////////////////////////	

	do{
		system("cls");
		cout<<"Main menu options:\n\n"<<endl;
		cout<<"\t\t1. Add New Taxi to standby queue"<<endl;
		cout<<"\t\t2. Check for actual data"<<endl;
		cout<<"\t\t3. Sent Taxi to a Client"<<endl;
		cout<<"\t\t4. Check for taxis in routes"<<endl;
		cout<<"\t\t5. Reinsert a taxi to avaialable queue"<<endl;
		cout<<"\t\t6. Check Travels Data"<<endl;
		cout<<"\t\t7. Check Travels Data For Car"<<endl;
		cout<<"\t\t8. Exit program"<<endl<<endl;
		cout<<"Please, input your option: ";
		cin>>option;
		switch(option){
			case 1:
				do{
					cout<<"Taxi ID:";
					cin>>id;
				}while(checkForItemInt(taxis, id));
				taxis.push_back(id);
				
				cout<<"Driver Name:";
				cin.ignore();
				getline(cin,driverName);
				driverName = convert(driverName);
				driversName.push_back(driverName);
				
				cout<<"Driver Last Name:";
				getline(cin,driverLastname);
				driverLastname = convert(driverLastname);
				driversLastname.push_back(driverLastname);
				
				do{
					cout<<"Driver ID:";
					cin>>driverId;
				}while(checkForItemInt(driversId, driverId));
				driversId.push_back(driverId);
				
				do{
					cout<<"Insurance Number of Driver:";
					cin.ignore();
					getline(cin,insuranceNumber);
					insuranceNumber = convert(insuranceNumber);
				}while(checkForItemInt(insuranceNumbers, insuranceNumber));
				insuranceNumbers.push_back(insuranceNumber);
				
				cout<<"Phone Number:";
				cin>>phoneNumber;
				phoneNumbers.push_back(phoneNumber);
				
				
				cout<<"Model Car:";
				cin.ignore();
				getline(cin,modelName);	
				modelName = convert(modelName);
				modelNames.push_back(modelName);
				
				cout<<"Year of the Car:";
				cin>>year;
				years.push_back(year);
				
				categories.push_back(getCategory(year));
				
				do{
					cout<<"Motor Number:";
					cin.ignore();
					getline(cin,motorNumber);
					motorNumber = convert(motorNumber);
				}while(checkForItemInt(motorNumbers, motorNumber));
				motorNumbers.push_back(motorNumber);
				
				do{
					cout<<"Plate Number:";
					getline(cin,plateNumber);
					plateNumber = convert(plateNumber);
				}while(checkForItemInt(plates, plateNumber));
				plates.push_back(plateNumber);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
				
				insertCarData(id,driverName, driverLastname, driverId, insuranceNumber, phoneNumber, modelName, year, motorNumber, plateNumber);			
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
			break;
			case 2:		
				printTable(taxis, driversName, driversLastname, driversId, insuranceNumbers, phoneNumbers, modelNames, years, motorNumbers, plates, categories);
			break;
			case 3:
				//code logic for sending taxis here
				cout << "Enter taxi category (Executive or Traditional): ";
				cin.ignore();
				getline(cin,taxiCategory);
				taxiCategory = convert(taxiCategory);
				
				cout << "Enter starting point: ";
				cin.ignore(0, '\n');
				getline(cin,starting_place);
				starting_place = convert(starting_place);
				
				
				cout << "Enter destination point: ";
				cin.ignore(0, '\n');
				getline(cin,destination_place);
				destination_place = convert(destination_place);
				
				
				cout << "Enter trip cost: ";
				cin >> cost;
				
					
	   			v = verificationTaxi(categories, taxiCategory);
				dateAndTime = getDateTime();  
	   			
				if(v.exists == 1)
				{
				sentTaxi(taxis, nAtaxis, nAyears, nAdriversId, nAphoneNumbers, nAdriversName, 
				nAdriversLastname, nAinsuranceNumbers, nAplates, nAmodelNames, nAmotorNumbers, 
				nAcategories, nAdates, nAstart_times, nAstarting_places, nAdestination_places, nAcosts, driversName, driversLastname, driversId, insuranceNumbers, 
				phoneNumbers, modelNames, years, motorNumbers, plates, categories, v.position, dateAndTime[0], dateAndTime[1], starting_place, destination_place, cost);
				}
				else if(v.exists == 0)
				{
				cout << "There are no taxis available with the category " << taxiCategory << endl;
				}		
					
			break;
			case 4:
				
				//code logic for on route checks
				cout<<"\n******************************************************************************* TAXIS ON ROUTE ************************************************************************** \n";
				printRouteTaxis(nAtaxis, nAyears, nAdriversId, nAphoneNumbers, nAdriversName, nAdriversLastname, 
					            nAinsuranceNumbers, nAplates, nAmodelNames, nAmotorNumbers, nAcategories, nAdates, nAstart_times);
					            
			break;
			case 5:
				
				//code logic for reinset taxis into avaialable queue
		
				cout<<"\n******************************************************************************* TAXIS ON ROUTE ************************************************************************** \n";
				printRouteTaxis(nAtaxis, nAyears, nAdriversId, nAphoneNumbers, nAdriversName, nAdriversLastname, 
					            nAinsuranceNumbers, nAplates, nAmodelNames, nAmotorNumbers, nAcategories, nAdates, nAstart_times);		
										
				// Obtener el ID del taxi que se desea devolver a la lista de espera
			    cout << "\n Enter the ID of the taxi to return to standby: ";
			    cin >> idToReinsert;
			    
			    // Llamar a la función returnToStandby para devolver el taxi a la lista de espera
			  
			    dateAndTime = getDateTime();
			    returnToStandby(taxis, nAtaxis, nAyears, nAdriversId, nAphoneNumbers, nAdriversName, 
				nAdriversLastname, nAinsuranceNumbers, nAplates, nAmodelNames, nAmotorNumbers, 
				nAcategories, nAdates, nAstart_times, nAstarting_places, nAdestination_places, nAcosts, driversName, driversLastname, driversId, insuranceNumbers, 
				phoneNumbers, modelNames, years, motorNumbers, plates, categories, idToReinsert, dateAndTime[1]);
				
			break;
			case 6:
				printTravelData(tr_taxis, tr_driversName, tr_driversLastname, tr_driversId, tr_modelNames, tr_years, tr_categories, 
								tr_dates, tr_start_times, tr_end_times, tr_starting_places, tr_destination_places, tr_costs, idtaxi);
			break;
			case 7:
				cout << "\n Enter the taxi id you want to check: ";
			    cin >> idtaxi;	
				printTravelData(tr_taxis, tr_driversName, tr_driversLastname, tr_driversId, tr_modelNames, tr_years, tr_categories, 
								tr_dates, tr_start_times, tr_end_times, tr_starting_places, tr_destination_places, tr_costs, idtaxi);			
			break;	
			case 8:
				cout<<"Program has ended...";
				system("pause");
				system("exit");
			break;	
			default:
				cout<<"Non correct option has been chosen."<<endl;
			break;
		}
  	cout<<"Want to continue? (Y/N)?: ";
  	response=getch();
	}while(response=='Y' || response=='y');	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool checkForItemInt(vector<int> arr, int data){
	for(int i=0;i<arr.size();i++)
	{
		if(arr.at(i)==data)
		{
			cout<<"Data is already registered at position ["<<i<<"].\nPlease Enter Data again.\n";
			return true;
		}
		else
		{
			return false;
		}
	}		
}

bool checkForItemInt(vector<string> arr, string data){
	for(int i=0;i<arr.size();i++)
	{
	if(arr.at(i)==data)
		{
			cout<<"Data is already registered at position ["<<i<<"].\nPlease Enter Data again.\n";
			return true;
		}
		else
		{
			return false;
		}
	}		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printTable(vector<int> taxis, vector<string> driversName, vector<string> driversLastname, vector<int> driversId, vector<string>insuranceNumbers, vector<int> phoneNumbers, vector<string> modelNames, vector<int> years, vector<string> motorNumbers, vector<string> plates, vector<string> categories) 
{
	TextTable t( '-', '|', '+' );
	//t.add(" Order ");
	t.add(" Taxi ID ");
	t.add(" Driver Name ");
	t.add(" Driver Last Name ");
	t.add(" Driver ID ");
	t.add(" Insurance Number of Driver ");
	t.add(" Phone Number ");
	t.add(" Model Car ");
	t.add(" Year of the Car ");
	t.add(" Motor Number ");
	t.add(" Plate Number "); 
	t.add(" Category ");
	t.endOfRow();
	for(int i=0; i<taxis.size();i++)
	{
		//t.add(to_string(i+1));
		t.add(to_string(taxis.at(i)));
		t.add(driversName.at(i));
		t.add(driversLastname.at(i));
		t.add(to_string(driversId.at(i)));
		t.add(insuranceNumbers.at(i));
		t.add(to_string(phoneNumbers.at(i)));
		t.add(modelNames.at(i));
		t.add(to_string(years.at(i)));
		t.add(motorNumbers.at(i));
		t.add(plates.at(i));
		t.add(categories.at(i));
		t.endOfRow();	
	}
	t.setAlignment( 2, TextTable::Alignment::LEFT );
	cout<<t;
}
