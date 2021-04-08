#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

class machine
{
public:
    string hostname;

    machine(string hostname, string address = "0.0.0.0")
        : hostname(hostname)
    {
        sscanf((char *)&address[0], "%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
        networks[((ip[0] << 8) | ip[1])].push_back(hostname);
    }

    static map<int, list<string>> networks;

private:
    int ip[4] = {0};
};

map<int, list<string>> machine::networks = map<int, list<string>>();

int main()
{
    machine("Atlas", "101.33.2.1");
    machine("Horizon", "101.33.56.80");
    // machine("Pluto", "101.43.45.74");

    for (auto &n : machine::networks)
    {
        cout << "Machines ";
        int i = 0;
        for (auto &m : n.second)
        {
            cout << m;

            if (++i == n.second.size() - 1)
                cout << " and ";
            else if (i - 1 == 0)
                cout << ", ";
        }
        cout << " are on the same local network" << endl;
    }

    return 0;
}
