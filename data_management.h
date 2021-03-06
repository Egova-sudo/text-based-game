#include<fstream>
#include<algorithm>
#include<tuple>
#include<sstream>

// Dummy functin to write elements of vector to savefile. (see std::for_each line)
// Couldnt come up with a direct procedure
void print_element( std::string x)
{
	std::cout << x << " ";
}

void save_file(std::tuple < std::vector<std::string>, std::vector<int>> data) {
	
	
	// Preprocess data
	auto names = std::get<0>(data);
	auto hps = std::get<1>(data);
	
    // Standard .txt file writing
	std::ofstream savefile;
	std::string file_name;
	std::cout << "Save file name: ";
	std::cin >> file_name;
	file_name.append(".csv");
	savefile.open(file_name, std::ios_base::app); // app stands for append at the end
	// check before writing to savefile object, whether the file is created in the folder
	if (savefile.is_open()) {

		// Player names
		savefile << "Players,";
		for (auto& x:names) {
			savefile << x << ",";
		}
		savefile << "\n";
		// Player stats
		savefile << "HPs,";
		for (auto& x : hps) {
			savefile << x << ",";
		}
		savefile << "\n";
	}	
	savefile.close();
}

std::tuple < std::vector<std::string>, std::vector<int>> load_file() {

	// Ask the user for save file name
	std::string file_name;
	std::cout << "File you want to load?: ";
	std::cin >> file_name;
	file_name.append(".csv");
	std::ifstream loadfile(file_name);
	std::string cell; 
	std::string label;
	std::string line;
	std::vector<std::string> names;
	std::vector<int> hps;

	// Read the csv file line-by-line
	int row_index = 0; int key;
	std::vector<std::string> labels {"Players", "HPs"};
	while ( std::getline(loadfile, line)) {

		//std::cout << line << std::endl; // Comment out this line to check what the line variable gets
		std::stringstream ss(line);
		
		// Appoint keys to access the switch cases to store data into different kinds of vectors
		std::getline(ss, label, ',');
		std::cout << label << " ";
		if (labels[0] == label) {
			key = 0;
		}
		else if (labels[1] == label) {
			key = 1;
		}

		while (std::getline(ss, cell, ',')) {			

			switch (key) {
			// Fetch player names
			case 0: {
				std::cout << cell << " ";
				names.push_back(cell);
				break;
			}
	        // Fetch player stats
			case 1:	{
				std::cout << cell << " ";
				hps.push_back(std::stoi(cell));
				break;
			}
			}
		}	
		row_index++;
	}
	loadfile.close();
	
	
	std::cout << "Size of names: " << names.size() << std::endl;
	std::cout << "Size of stats: " << hps.size() << std::endl;
	std::cout << "Counter: " << row_index << std::endl;
	//std::for_each(line.begin(),line.end(),print_element);
	
	// Shape data into tuple of string vector and int vector
	std::tuple < std::vector<std::string>, std::vector<int>> data = {names, hps};
	return data;
	}

