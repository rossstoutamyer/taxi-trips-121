#include <stdexcept>
#include <string>
#include "taxi_trips.h"
using std::string;

bool is_payment_valid(string type, string valid_types[], unsigned int size) {
	if (size <= 0) {
		throw std::invalid_argument("");
	}
	
	for (unsigned int i = 0; i < size; i++) {
		if (type == valid_types[i]) {
			return true;
		}
	}
  
	return false;
}

double max(double values[], unsigned int size) {
	double maxNum = 0;
	
	if (size < 1) {
		throw std::invalid_argument("");
	}
	
	for (unsigned int i = 0; i < size; i++) {
		if (values[i] >= maxNum) {
			maxNum = values[i];
		}
	}
	
	return maxNum;
}

double min(double values[], unsigned int size) {
	double minNum = values[0];
	
	if (size < 1) {
		throw std::invalid_argument("");
	}
	
	for (unsigned int i = 1; i < size; i++) {
		if (values[i] <= minNum) {
			minNum = values[i];
		}
	}
	
	return minNum;
}

double average(double values[], unsigned int size) {
	double listSum = 0;
	int numVals = 0;
	
	if (size < 1) {
		throw std::invalid_argument("");
	}
	
	for (unsigned int i = 0; i < size; i++) {
		if (values[i] >= 0) {
			listSum += values[i];
			++numVals;
		}
	}
	
	return (listSum / numVals);
}

double mode(double values[], unsigned int size) {
	int modeIndx = 0;
	int modeNum = 0;
	int counter = 1;
	
	if (size < 1) {
		throw std::invalid_argument("");
	}
	
	for (unsigned int i = 0; i < size - 1; i++) {
		for (unsigned int j = i + 1; j < size; j++) {
			if (values[i] == values[j]) {
				counter++;
			}
		}
		if (counter > modeNum) {
			modeNum = counter;
			modeIndx = i;
		}
		counter = 1;
	}
	
	return values[modeIndx];
}

unsigned int length_longest_seq_zeros(double values[], unsigned int size) {
	unsigned int counter = 0;
	unsigned int maxSequence = 0;
	
	if (size < 1) {
		throw std::invalid_argument("");
	}
	
	for (unsigned int i = 0; i < size; i++) {
		if (values[i] == 0) {
			++counter;
		} else {
			counter = 0;
		}
		if (counter > maxSequence) {
			maxSequence = counter;
		}
	}
	
	return maxSequence;
}