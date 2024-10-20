/*
* Armon Wilson
* SNHU
* CS210 - Programming Languages
* Module 7 - Project 3
*/

#pragma once
#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

using namespace std;

// Class structure
class ItemTracker {
private:
    map <string, int> itemFrequency;
    const string dataFile = "frequency.dat";

    void ReadInputData();
    void WriteDataBackup();

public:
    ItemTracker();
    void FindItemFrequency();
    void PrintAllItemFrequencies();
    void PrintItemHistogram();
};

#endif
