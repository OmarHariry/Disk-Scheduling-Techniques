#include<bits/stdc++.h>
using namespace std;
void FIFO(vector<int>request, int pos, int disk);
void SCAN(vector<int>request, int pos, int disk, int dir);
void C_SCAN(vector<int>request, int pos, int disk, int dir);
int main()
{
	vector<int>request;
	int n, pos, dir, disk, x;					//number of requests and starting position	//type of schedulling
	cout << "Choose the schedulling type: \n1)FIFO\n2)SCAN\n3)C_SCAN\n";
	cin >> x;
	cout << "Enter the size of disk" << endl;
	cin >> disk;
	cout << "Enter the number of requests" << endl;
	cin >> n;
	cout << "Enter the requests" << endl;
	while (n--) {
		int temp;
		cin >> temp;
		assert(disk >= temp);
		request.push_back(temp);
	}
	cout << "Enter the head position" << endl;
	cin >> pos;
	cout << "Enter the head direction" << endl;
	cin >> dir;									//0 decreasing , 1 increasing
	assert(dir == 0 || dir == 1);

	switch (x) {
	case 1: FIFO(request, pos, disk); break;
	case 2: SCAN(request, pos, disk, dir); break;
	case 3: C_SCAN(request, pos, disk, dir); break;
	}

}
//27 129 110 186 147 41 10 64 120
void FIFO(vector<int>request, int pos, int disk) {
	int count = 0, sum = 0;
	cout << pos << " -> ";
	for (int i = 0; i < request.size(); ++i) {
		++count;
		sum += (fabs(pos - request[i]));
		pos = request[i];
		if (i == request.size() - 1) {
			cout << request[i] << endl;
		}
		else {
			cout << request[i] << " -> ";
		}
	}
	cout << "Total head movements = " << sum << endl;
	cout << "Average head movement = " << double(sum) / count;
}
void SCAN(vector<int>request, int pos, int disk, int dir) {
	request.push_back(pos);
	sort(request.begin(), request.end());
	int count = 0, sum = 0, reserve = pos;
	//cout << pos << " -> ";
	map<int, int>mp;
	for (int i = 0; i < request.size(); ++i) {
		mp[request[i]] = i;
	}
	if (dir == 0) {
		for (int i = mp[reserve]; i >= 0; --i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			cout << request[i] << " -> ";
		}
		for (int i = mp[reserve] + 1; i < request.size(); ++i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			if (i == request.size() - 1) {
				cout << request[i] << endl;
			}
			else {
				cout << request[i] << " -> ";
			}
		}

	}
	else {
		for (int i = mp[reserve]; i < request.size(); ++i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			cout << request[i] << " -> ";
		}
		for (int i = mp[reserve] - 1; i >= 0; --i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			if (i == 0) {
				cout << request[i] << endl;
			}
			else {
				cout << request[i] << " -> ";
			}
		}

	}
	--count;
	cout << "Total head movements = " << sum << endl;
	cout << "Average head movement = " << double(sum) / count;
}
void C_SCAN(vector<int>request, int pos, int disk, int dir) {
	request.push_back(pos);
	sort(request.begin(), request.end());
	int count = 0, sum = 0, reserve = pos;
	//cout << pos << " -> ";
	map<int, int>mp;
	for (int i = 0; i < request.size(); ++i) {
		mp[request[i]] = i;
	}
	if (dir == 0) {
		for (int i = mp[reserve]; i >= 0; --i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			cout << request[i] << " -> ";
		}
		for (int i = request.size() - 1; i > mp[reserve]; --i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			if (i == mp[reserve] + 1) {
				cout << request[i] << endl;
			}
			else {
				cout << request[i] << " -> ";
			}
		}
	}
	else {
		for (int i = mp[reserve]; i < request.size(); ++i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			cout << request[i] << " -> ";
		}
		for (int i = 0; i < mp[reserve]; ++i) {
			++count;
			sum += (fabs(pos - request[i]));
			pos = request[i];
			if (i == mp[reserve] - 1) {
				cout << request[i] << endl;
			}
			else {
				cout << request[i] << " -> ";
			}
		}
	}
	--count;
	cout << "Total head movements = " << sum << endl;
	cout << "Average head movement = " << double(sum) / count;

}
