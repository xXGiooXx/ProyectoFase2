#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //BIBLIOTECA PARA UTILIZAR LA FUNCION transform()
#include<ctime>



using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string convert(string& word)
{
	transform(word.begin(), word.end(), word.begin(), ::toupper); // Convertir la entrada taxiCategory en mayúscula
	return word;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string getCategory(int year) 
{
    if (year < 2010) {
        return "Doesnt meet the requirements";
    } else if (year < 2015) {
        return "TRADITIONAL";
    } else {
        return "EXECUTIVE";
    }
}
//////////////////////////////////////////////////////////////Agrupacion de dos valores de retorno/////////////////////////////////////////////////////////////////////////////////////////
struct VerificationData{
	bool exists;
	int position;
};

VerificationData verificationTaxi( vector <string> categories, string taxiCategory) 
{
	VerificationData v;
	v.exists = false;
	for (int i = 0; i < categories.size(); i++) 
	{
		if (categories[i] == taxiCategory) 
		{	// buscar el primer taxi disponible con la categoría correspondiente y retornar un true.       
			v.exists = true;
			v.position = i;	
			break;		
		}
		// si no hay taxis disponibles con la categoría requerida retornar un false.
	}
	return v;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> getDateTime() {
	
    vector<string> dateAndTime;

    // Obtiene el tiempo actual
    time_t currentTime = time(NULL);

    // Convierte el tiempo en una estructura tm
    tm* dateTime = localtime(&currentTime);

    // Formato de fecha
    char dateformat[] = "%d-%m-%Y";

    // Buffer para almacenar la fecha formateada
    char dateBuffer[80];

    // Formatea la fecha en el buffer
    strftime(dateBuffer, sizeof(dateBuffer), dateformat, dateTime);

    // Convierte el buffer en una cadena de C++
    string formattedDate(dateBuffer);

    // Almacena la fecha en la posición 0 del vector
    dateAndTime.push_back(formattedDate);

    // Formato de hora
    char timeformat[] = "%I:%M %p";

    // Buffer para almacenar la hora formateada
    char timeBuffer[80];

    // Formatea la hora en el buffer
    strftime(timeBuffer, sizeof(timeBuffer), timeformat, dateTime);

    // Convierte el buffer en una cadena de C++
    string formattedTime(timeBuffer);

    // Almacena la hora en la posición 1 del vector
    dateAndTime.push_back(formattedTime);

    // Retorna el vector con la fecha y hora
    return dateAndTime;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string addSpacesToText(string& text) {
    string result;
    for (char c : text) {
        if (c == '_') {
            result += ' ';
        } else {
            result += c;
        }
    }
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertCarData(int id, string driverName, string driverLastname, int driverId, string insuranceNumber, int phoneNumber, string modelName, int year, string motorNumber, string plateNumber)
{
	ofstream carDataFile ("CARS_STORAGE.txt", ios::app);
	if(carDataFile.is_open())
		{
			carDataFile << id << " " << driverName<< " " << driverLastname << " " << driverId<< " " << insuranceNumber << " " << phoneNumber << " " << modelName << " " << year << " " <<  motorNumber << " " << plateNumber << " " << getCategory(year) << "\n";
			carDataFile.close();
		}
		else
		{
			cout << "No save";
		}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertCarDataOnRoute(int id, string driverName, string driverLastname, int driverId, string insuranceNumber, int phoneNumber, string modelName, int year, string motorNumber, string plateNumber, string category, string date, string time, string start_place, string destiny, double cost )
{
	ofstream onRouteDataFile ("CARS_ON_ROUTE.txt", ios::app);
	
	time.erase(remove(time.begin(), time.end(), ' '), time.end());
    start_place.erase(remove(start_place.begin(), start_place.end(), ' '), start_place.end());
    destiny.erase(remove(destiny.begin(), destiny.end(), ' '), destiny.end());
	
	if(onRouteDataFile.is_open())
		{
			onRouteDataFile << id << " " << driverName<< " " << driverLastname << " " << driverId<< " " << insuranceNumber << " " << phoneNumber << " " << modelName << " " << year << " " <<  motorNumber << " " << plateNumber << " " << category << " " << date << " " << time << " " << start_place << " " << destiny << " " << cost << "\n";
			onRouteDataFile.close();
		}
		else
		{
			cout << "No save";
		}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertDataTravels(int id, string driverName, string driverLastname, int driverId, string modelName, int year, string category, string date, string start_time, string endtime, string start_place, string destiny, double cost)
{
	ofstream dataTravelFile ("TRAVEL_DATA.txt", ios::app);
	
	start_time.erase(remove(start_time.begin(), start_time.end(), ' '), start_time.end());
    start_place.erase(remove(start_place.begin(), start_place.end(), ' '), start_place.end());
    destiny.erase(remove(destiny.begin(), destiny.end(), ' '), destiny.end());
    
	if(dataTravelFile.is_open())
		{
			dataTravelFile << id << " " << driverName << " " << driverLastname << " " << driverId<< " " << modelName << " " << year << " " << category << " " << date << " " << start_time << " " << endtime << " " << start_place << " " << destiny << " " << cost << "\n";
			dataTravelFile.close();
		}
		else
		{
			cout << "No save";
		}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadCardataFromFile(vector<int>& taxis, vector<string>& driversName, vector<string>& driversLastname,
                             vector<int>& driversId, vector<string>& insuranceNumbers, vector<int>& phoneNumbers,
                             vector<string>& modelNames, vector<int>& years, vector<string>& motorNumbers,
                             vector<string>& plates, vector<string>& categories) {
                             	
    ifstream file("CARS_STORAGE.txt");
    
    string driverName, driverLastname, insuranceNumber, modelName, motorNumber, plate, category, date, time;
    int id, driverId, phoneNumber, year;

    while (file >> id >> driverName >> driverLastname >> driverId >> insuranceNumber >> phoneNumber >>
           modelName >> year >> motorNumber >> plate >> category ) {
           	
        taxis.push_back(id);
        driversName.push_back(driverName);
        driversLastname.push_back(driverLastname);
        driversId.push_back(driverId);
        insuranceNumbers.push_back(insuranceNumber);
        phoneNumbers.push_back(phoneNumber);
        modelNames.push_back(modelName);
        years.push_back(year);
        motorNumbers.push_back(motorNumber);
        plates.push_back(plate);
        categories.push_back(category);
    }

    file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadOnRoutedataFromFile(vector<int>& nAtaxis, vector<string>& nAdriversName, vector<string>& nAdriversLastname,
                             vector<int>& nAdriversId, vector<string>& nAinsuranceNumbers, vector<int>& nAphoneNumbers,
                             vector<string>& nAmodelNames, vector<int>& nAyears, vector<string>& nAmotorNumbers,
                             vector<string>& nAplates, vector<string>& nAcategories, vector<string>& nAdates, 
							 vector<string>& nAstart_times, vector<string>& nAstarting_places, vector<string>& nAdestination_places, vector<double>& nAcosts) {
                             	
    ifstream file("CARS_ON_ROUTE.txt");
    
    string driverName, driverLastname, insuranceNumber, modelName, motorNumber, plate, category, date, start_time, start_place, destiny;
    int id, driverId, phoneNumber, year;
	double cost;

    while (file >> id >> driverName >> driverLastname >> driverId >> insuranceNumber >> phoneNumber >>
           modelName >> year >> motorNumber >> plate >> category >> date >> start_time >> start_place >> destiny >> cost) {
        
		start_time = start_time.substr(0, 2) + "" + start_time.substr(2, 2) + "" + start_time.substr(4) + " ";
        start_place = addSpacesToText(start_place);
        destiny = addSpacesToText(destiny);   	
           	
        nAtaxis.push_back(id);
        nAdriversName.push_back(driverName);
        nAdriversLastname.push_back(driverLastname);
        nAdriversId.push_back(driverId);
        nAinsuranceNumbers.push_back(insuranceNumber);
        nAphoneNumbers.push_back(phoneNumber);
        nAmodelNames.push_back(modelName);
        nAyears.push_back(year);
        nAmotorNumbers.push_back(motorNumber);
        nAplates.push_back(plate);
        nAcategories.push_back(category);
        nAdates.push_back(date);
        nAstart_times.push_back(start_time);
        nAstarting_places.push_back(start_place);
        nAdestination_places.push_back(destiny);
      	nAcosts.push_back(cost);
    }

    file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadTravelDataFromFile(vector<int>& tr_taxis, vector<string>& tr_driversName, vector<string>& tr_driversLastname,
                             vector<int>& tr_driversId, vector<string>& tr_modelNames, vector<int>& tr_years, vector<string>& tr_categories, vector<string>& tr_dates, 
							 vector<string>& tr_start_times, vector<string>& tr_end_times, vector<string>& tr_starting_places, vector<string>& tr_destination_places, vector<double>& tr_costs) {
                             	
    ifstream file("TRAVEL_DATA.txt");
    string driverName, driverLastname, modelName, category, date, start_time, endtime, start_place, destiny;
    int id, driverId, year;
	double cost;

    while (file >> id >> driverName >> driverLastname >> driverId >> modelName >> year >> category >> date >> start_time >> endtime >> start_place >> destiny >> cost) {
    	
        
		
		start_time = start_time.substr(0, 2) + "" + start_time.substr(2, 2) + "" + start_time.substr(4) + " ";
		endtime = endtime.substr(0, 2) + "" + endtime.substr(2, 2) + "" + endtime.substr(4) + " ";
        start_place = addSpacesToText(start_place);
        destiny = addSpacesToText(destiny); 	
        	
        tr_taxis.push_back(id);
        tr_driversName.push_back(driverName);
        tr_driversLastname.push_back(driverLastname);
        tr_driversId.push_back(driverId);
        tr_modelNames.push_back(modelName);
        tr_years.push_back(year);
        tr_categories.push_back(category);
        tr_dates.push_back(date);
        tr_start_times.push_back(start_time);
        tr_end_times.push_back(endtime);
        tr_starting_places.push_back(start_place);
        tr_destination_places.push_back(destiny);
        tr_costs.push_back(cost);

    }

    file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void removeCarDataFromFile(int taxiID) {
	
    ifstream inFile("CARS_STORAGE.txt");
    ofstream outFile("temp.txt");

    if (inFile && outFile) {
        string line;
        while (getline(inFile, line)) {
            int id;
            stringstream data(line);
            data >> id;

            if (id != taxiID) {
                outFile << line << endl;
            }
        }

        inFile.close();
        outFile.close();

        remove("CARS_STORAGE.txt");
        rename("temp.txt", "CARS_STORAGE.txt");
    } else {
        cout << "Error: Unable to open file." << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void removeOnRouteFromFile(int taxiID) {
	
    ifstream inFile("CARS_ON_ROUTE.txt");
    ofstream outFile("temp.txt");

    if (inFile && outFile) {
        string line;
        while (getline(inFile, line)) {
            int id;
            stringstream data(line);
            data >> id;

            if (id != taxiID) {
                outFile << line << endl;
            }
        }

        inFile.close();
        outFile.close();

        remove("CARS_ON_ROUTE.txt");
        rename("temp.txt", "CARS_ON_ROUTE.txt");
    } else {
        cout << "Error: Unable to open file." << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sentTaxi( vector<int>& taxis, vector<int>& nAtaxis, vector<int>& nAyears, vector<int>& nAdriversId, vector<int>& nAphoneNumbers, vector<string>& nAdriversName, 
			 vector<string>& nAdriversLastname, vector<string>& nAinsuranceNumbers, vector<string>& nAplates, vector<string>& nAmodelNames, vector<string>& nAmotorNumbers, vector<string>& nAcategories, 
			 vector<string>& nAdates, vector<string>& nAstart_times, vector<string>& nAstarting_places, vector<string>& nAdestination_places, vector<double>& nAcosts, vector<string>& driversName, vector<string>& driversLastname, vector<int>& driversId, vector<string>& insuranceNumbers, vector<int>& phoneNumbers, 
			 vector<string>& modelNames, vector<int>& years, vector<string>& motorNumbers, vector<string>& plates, vector<string>& categories, int position, string date, string time, string start_place, string destiny, double cost)
{	

	//agregar a la cola de taxis en ruta 
	nAtaxis.push_back(taxis[position]); 
	nAyears.push_back(years[position]);  
	nAdriversId.push_back(driversId[position]);
	nAphoneNumbers.push_back(phoneNumbers[position]);
	nAdriversName.push_back(driversName[position]);
	nAdriversLastname.push_back(driversLastname[position]);
	nAinsuranceNumbers.push_back(insuranceNumbers[position]);
	nAplates.push_back(plates[position]);
	nAmodelNames.push_back(modelNames[position]);
	nAmotorNumbers.push_back(motorNumbers[position]);
	nAcategories.push_back(categories[position]);
	nAdates.push_back(date);
	nAstart_times.push_back(time);
	nAstarting_places.push_back(start_place);
	nAdestination_places.push_back(destiny);
	nAcosts.push_back(cost);
	
	insertCarDataOnRoute(taxis[position], driversName[position], driversLastname[position], driversId[position], insuranceNumbers[position], phoneNumbers[position], modelNames[position], years[position], motorNumbers[position], plates[position], categories[position], date, time, start_place, destiny, cost);
	removeCarDataFromFile(taxis[position]);
							
	//quitar el taxi de la cola de taxis disponibles						
	taxis.erase(taxis.begin() + position);
	driversName.erase(driversName.begin() + position);
	driversLastname.erase(driversLastname.begin() + position);
	driversId.erase(driversId.begin() + position);
	insuranceNumbers.erase(insuranceNumbers.begin() + position);
	phoneNumbers.erase(phoneNumbers.begin() + position);
	modelNames.erase(modelNames.begin() + position);
	years.erase(years.begin() + position);
	motorNumbers.erase(motorNumbers.begin() + position);
	plates.erase(plates.begin() + position);
	categories.erase(categories.begin() + position);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printRouteTaxis(vector<int>& nAtaxis, vector<int>& nAyears, vector<int>& nAdriversId, vector<int>& nAphoneNumbers, vector<string>& nAdriversName, 
					 vector<string>& nAdriversLastname, vector<string>& nAinsuranceNumbers, vector<string>& nAplates, vector<string>& nAmodelNames, 
					 vector<string>& nAmotorNumbers, vector<string>& nAcategories, vector<string>& nAdates, vector<string>& nAstart_times)
{
    TextTable t('-', '|', '+');
    //t.add(" Order ");
	t.add(" Taxi ID ");
	t.add(" Driver Name ");
	t.add(" Driver Last Name ");
	t.add(" Driver ID ");
	t.add(" Insurance Number ");
	t.add(" Phone Number ");
	t.add(" Model Car ");
	t.add(" Year ");
	t.add(" Motor Number ");
	t.add(" Plate Number "); 
	t.add(" Category ");
	t.add(" Date "); 
	t.add(" StartTime ");
    t.endOfRow();
    for (int i = 0; i < nAtaxis.size(); i++)
    {
        //t.add(to_string(i+1));
        t.add(to_string(nAtaxis.at(i)));
        t.add(nAdriversName.at(i));
		t.add(nAdriversLastname.at(i));
		t.add(to_string(nAdriversId.at(i)));
		t.add(nAinsuranceNumbers.at(i));
		t.add(to_string(nAphoneNumbers.at(i)));
		t.add(nAmodelNames.at(i));
		t.add(to_string(nAyears.at(i)));
		t.add(nAmotorNumbers.at(i));
		t.add(nAplates.at(i));
		t.add(nAcategories.at(i));
		t.add(nAdates.at(i));
		t.add(nAstart_times.at(i));
        t.endOfRow();
    }
    t.setAlignment(0, TextTable::Alignment::LEFT);
    cout << t;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void returnCarData(int id, string driverName, string driverLastname, int driverId, string insuranceNumber, int phoneNumber, string modelName, int year, string motorNumber, string plateNumber, string category)
{
	ofstream returnDataFile ("CARS_STORAGE.txt", ios::app);
	if(returnDataFile.is_open())
		{
			returnDataFile << id << " " << driverName<< " " << driverLastname << " " << driverId<< " " << insuranceNumber << " " << phoneNumber << " " << modelName << " " << year << " " <<  motorNumber << " " << plateNumber << " " << category << "\n";
			returnDataFile.close();
		}
		else
		{
			cout << "No save";
		}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void returnToStandby(vector<int>& taxis, vector<int>& nAtaxis, vector<int>& nAyears, vector<int>& nAdriversId, vector<int>& nAphoneNumbers, vector<string>& nAdriversName, 
					vector<string>& nAdriversLastname, vector<string>& nAinsuranceNumbers, vector<string>& nAplates, vector<string>& nAmodelNames, vector<string>& nAmotorNumbers, vector<string>& nAcategories,
					vector<string>& nAdates, vector<string>& nAstart_times, vector<string>& nAstarting_places, vector<string>& nAdestination_places, vector<double>& nAcosts, vector<string>& driversName, 
					vector<string>& driversLastname, vector<int>& driversId, vector<string>& insuranceNumbers, vector<int>& phoneNumbers, 
					vector<string>& modelNames, vector<int>& years, vector<string>& motorNumbers, vector<string>& plates, vector<string>& categories, int idToReinsert, string endtime)
{                   
    int index = -1;
    
    for(int i=0; i < nAtaxis.size(); i++)
	{
		if(idToReinsert == nAtaxis[i])
		{
			index = i;
			break;
			
		}		
	}
	
	if(index == -1)
	{
		cout << "!!There are no taxis on routes with that id!! ";
		return;
	}
	
	// Agregar el taxi de vuelta a la lista de espera
	        taxis.push_back(nAtaxis[index]);
	        driversName.push_back(nAdriversName[index]);
	        driversLastname.push_back(nAdriversLastname[index]);
	        driversId.push_back(nAdriversId[index]);
	        insuranceNumbers.push_back(nAinsuranceNumbers[index]);
	        phoneNumbers.push_back(nAphoneNumbers[index]);
	        modelNames.push_back(nAmodelNames[index]);
	        years.push_back(nAyears[index]);
	        motorNumbers.push_back(nAmotorNumbers[index]);
	        plates.push_back(nAplates[index]);
	        categories.push_back(nAcategories[index]);
	        
	    	endtime.erase(remove(endtime.begin(), endtime.end(), ' '), endtime.end());
	    	
	        insertDataTravels(nAtaxis[index], nAdriversName[index], nAdriversLastname[index], nAdriversId[index], nAmodelNames[index], nAyears[index], nAcategories[index], nAdates[index], nAstart_times[index], endtime, nAstarting_places[index], nAdestination_places[index], nAcosts[index]);
			
			returnCarData(nAtaxis[index], nAdriversName[index], nAdriversLastname[index], nAdriversId[index], nAinsuranceNumbers[index], nAphoneNumbers[index], nAmodelNames[index], nAyears[index], nAmotorNumbers[index], nAplates[index], nAcategories[index]);
			removeOnRouteFromFile(nAtaxis[index]);
			
	        // Eliminar el taxi de la cola de taxis en ruta
	        nAtaxis.erase(nAtaxis.begin() + index);
	        nAdriversName.erase(nAdriversName.begin() + index);
	        nAdriversLastname.erase(nAdriversLastname.begin() + index);
	        nAdriversId.erase(nAdriversId.begin() + index);
	        nAinsuranceNumbers.erase(nAinsuranceNumbers.begin() + index);
	        nAphoneNumbers.erase(nAphoneNumbers.begin() + index);
	        nAmodelNames.erase(nAmodelNames.begin() + index);
	        nAyears.erase(nAyears.begin() + index);
	        nAmotorNumbers.erase(nAmotorNumbers.begin() + index);
	        nAplates.erase(nAplates.begin() + index);
	        nAcategories.erase(nAcategories.begin() + index);
	        nAdates.erase(nAdates.begin() + index);
	        nAstart_times.erase(nAstart_times.begin() + index);
	        nAstarting_places.erase(nAstarting_places.begin() + index);
	        nAdestination_places.erase(nAdestination_places.begin() + index);
	        nAcosts.erase(nAcosts.begin() + index);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
