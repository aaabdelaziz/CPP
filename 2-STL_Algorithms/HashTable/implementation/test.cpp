
#include <iostream>
#include <algorithm>
#include "HashTable.cpp"

using namespace std;

//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+

static void test()
{

    {
        cout << "\n----- Test: Keys From Empty Table -----\n";
        HashTable ht;
        vector<string> expectedKeys;
        vector<string> actualKeys = ht.keys();
        cout << "Retrieving keys from an empty table - EXPECTED: 0 keys\n";
        cout << (actualKeys == expectedKeys ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Keys Single Value -----\n";
        HashTable ht;
        ht.set("key1", 42);
        vector<string> expectedKeys{"key1"};
        vector<string> actualKeys = ht.keys();
        cout << "Retrieving a single key - EXPECTED: key1\n";
        cout << (actualKeys == expectedKeys ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Keys Multiple Values -----\n";
        HashTable ht;
        ht.set("key1", 42);
        ht.set("key2", 24);
        vector<string> expectedKeys{"key1", "key2"};
        vector<string> actualKeys = ht.keys();
        sort(actualKeys.begin(), actualKeys.end());
        cout << "Retrieving multiple keys - EXPECTED: key1, key2\n";
        cout << (actualKeys == expectedKeys ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Keys Collision Values -----\n";
        HashTable ht;
        ht.set("key1", 42);
        ht.set("collision", 23);
        vector<string> expectedKeys{"collision", "key1"};
        vector<string> actualKeys = ht.keys();
        sort(actualKeys.begin(), actualKeys.end());
        cout << "Retrieving keys with collision - EXPECTED: key1, collision\n";
        cout << (actualKeys == expectedKeys ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Keys Large Number of Values -----\n";
        HashTable ht;
        vector<string> expectedKeys;
        for (int i = 0; i < 100; i++)
        {
            string key = "key" + to_string(i);
            ht.set(key, i);
            expectedKeys.push_back(key);
        }
        vector<string> actualKeys = ht.keys();
        sort(actualKeys.begin(), actualKeys.end());
        sort(expectedKeys.begin(), expectedKeys.end());
        cout << "Retrieving a large number of keys - EXPECTED: key0 to key99\n";
        cout << (actualKeys == expectedKeys ? "PASS\n" : "FAIL\n");
    }
}
