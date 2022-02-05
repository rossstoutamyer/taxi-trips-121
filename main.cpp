#include <iostream>
#include <fstream>
#include <string>
#include "taxi_trips.h"
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() {
  const unsigned int MAX_TRIPS = 10000;
  string fileName = "";
  ifstream fin;
  string taxiID[MAX_TRIPS] = {};
  double tripSeconds[MAX_TRIPS] = {};
  double tripMiles[MAX_TRIPS] = {};
  double tripFare[MAX_TRIPS] = {};
  double tripTip[MAX_TRIPS] = {};
  string paymentType[MAX_TRIPS] = {};
  int invalidTrip = 0;
  string valid_types[] = {"CreditCard", "Cash", "NoCharge", "Unknown"};
  int validSize = 4;
  int numTrips = 0;
  int i = 0;
  double avgDuration = 0;
  double avgDistance = 0;
  double avgFare = 0;
  double avgTip = 0;
  double modeDuration = 0;
  double modeDistance = 0;
  double modeFare = 0;
  double modeTip = 0;
  double maxDuration = 0;
  double maxDistance = 0;
  double maxFare = 0;
  double maxTip = 0;
  double minDuration = 0;
  double minDistance = 0;
  double minFare = 0;
  double minTip = 0;
  int noTipSequence = 0;
  
  cout  << "Enter name of input file: ";
  cin >> fileName;
  
  fin.open(fileName);
  
  if (!fin.is_open()) {
	  cout << "Can't open " << fileName << endl;
	  return 1;
  }
  
  while (!fin.eof()) {
	  fin >> taxiID[i];
	  fin >> tripSeconds[i];
	  fin >> tripMiles[i];
	  fin >> tripFare[i];
	  fin >> tripTip[i];
	  fin >> paymentType[i];
	  
	  if (fin.fail()) {
		  break;
	  }
	  
	  if (tripSeconds[i] > 86400) {
		  ++invalidTrip;
		  --i;
	  } else if (tripMiles[i] > 1500) {
		  ++invalidTrip;
		  --i;
	  } else if ((tripFare[i] + tripTip[i]) > 5000) {
		  ++invalidTrip;
		  --i;
	  } else if (!is_payment_valid(paymentType[i], valid_types, validSize)) {
		  ++invalidTrip;
		  --i;
	  } else {
		++numTrips;
	  }
	  ++i;
  }
  
  fin.close();
  
  maxDistance = max(tripMiles, i);
  maxDuration = max(tripSeconds, i);
  maxFare = max(tripFare, i);
  maxTip = max(tripTip, i);
  minDistance = min(tripMiles, i);
  minDuration = min(tripSeconds, i);
  minFare = min(tripFare, i);
  minTip = min(tripTip, i);
  modeDistance = mode(tripMiles, i);
  modeDuration = mode(tripSeconds, i);
  modeFare = mode(tripFare, i);
  modeTip = mode(tripTip, i);
  avgDistance = average(tripMiles, i);
  avgDuration = average(tripSeconds, i);
  avgFare = average(tripFare, i);
  avgTip = average(tripTip, i);
  noTipSequence = length_longest_seq_zeros(tripTip, i);
  
  cout << "Number of trips: " << numTrips << endl;
  cout << "Number of trips with invalid data: " << invalidTrip << endl;
  cout << "Duration: max " << maxDuration << " min " << minDuration << " avg " << avgDuration << " mode " << modeDuration << endl;
  cout << "Distance: max " << maxDistance << " min " << minDistance << " avg " << avgDistance << " mode " << modeDistance << endl;
  cout << "Fare: max " << maxFare << " min " << minFare << " avg " << avgFare << " mode " << modeFare << endl;
  cout << "Tip: max " << maxTip << " min " << minTip << " avg " << avgTip << " mode " << modeTip << endl;
  cout << "Length of longest sequence without tips: " << noTipSequence << endl;

  return 0;
}