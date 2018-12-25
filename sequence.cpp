//
// Created by Matthew Weise on 2/13/2017.
//

#include "sequence.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;
using namespace main_savitch_3;

//DEFINE CONSTRUCTOR
sequence::sequence(){
    used = 0;
    current_index = 0;
};

//IMPLEMENT START FUNCTION
//PRE-CONDITION: USED = 0, IF NOT, RESETS SEQUENCE.
//POST CONDITION: SETS CURRENT_INDEX TO INDEX 0
void sequence::start() {
    if (used > 0) {
        current_index = 0;
    } else {
        current_index = used;
    }
}

//IMPLEMENT ADVANCE FUNCTION
//PRE-CONDITION: IF SEQUENCE IS ON A ITEM
//POST-CONDITION: MOVE INDEX FORWARD
void sequence::advance() {
        if(is_item()){
            current_index++;
        }
        else{
            cout << "NO ITEM" << endl;
        }
    }

//IMPLEMENT INSERT FUNCTION
//PRE-CONDITION: CURRENT SIZE OF SEQUENCE MUST BE LESS THAN THE POSSIBLE CAPACITY
//POST-CONDITION: POSITIONS SEQUENCE TO INDEX, AND PUTS ENTRY IN THE CURRENT INDEX
void sequence::insert(const value_type &entry) {
    if (size()<CAPACITY){
        if (!is_item()){
            start();
        }

        for(size_t i = used; i > current_index; i--){
            data[i] = data[i-1];
        }
        data[current_index] = entry;
        used++;
    }
}

//IMPLEMENT ATTACH FUNCTION
//PRE-CONDITION: CURRENT SIZE MUST BE LESS THAN POSSIBLE CAPACITY
//POST-CONDITION: "ATTACHES" ENTRY TO END OF SEQUENCE IF CURRENT_ITEM IS NOT PRESENT
//OTHERWISE, IT PUTS ENTRY AFTER CURRENT_ITEM IF PRESENT
void sequence::attach(const value_type &entry) {
    if(size() < CAPACITY){
        if(is_item()){
            for (size_t i = used; i > current_index + 1; i--){
                data[i] = data[i-1];
            }
            data[current_index +1] = entry;
            current_index++;
            used++;
        }

        else{
            data[used] = entry;
            current_index = used;
            used++;
        }
    }
    else{
        cout << "ATTACH NOT PERFORMED, size > Capacity" << endl;
    }
}

//IMPLEMENT REMOVE_CURRENT FUNCTION
//PRE-CONDITION: CHECKS TO SEE IF THE CURRENT INDEX IS ITEM
//POST-CONDITION: REMOVES ITEM FROM SEQUENCE, AND THE FOLLOWING ITEM IS NOW THE CURRENT ITEM
void sequence::remove_current() {
    if(is_item()){
        for (size_t i = current_index; i<used; i++){
            data[i] = data[i+1];
        }
        used--;
    }
    else{
        cout << "NO CURRENT ITEM" << endl;
    }
}

//IMPLEMENT IS_ITEM FUNCTION
//IF CURRENT INDEX >= 0 AND CURRENT INDEX < USED SPACE AND USED DOES NOT EQUAL 0, RETURN TRUE
bool sequence::is_item() const {
    return ((current_index >=0) && (current_index < used) && used != 0);
}

//RETURN CONSTANT
sequence::size_type sequence::size() const {
    return used;
}

//RETURN CURRENT INDEX ELEMENT
sequence::value_type sequence::current() const {
    if (is_item()){
        return data[current_index];
    }
    else{
        cout << "NO CURRENT ITEM" << endl;
    }
}


