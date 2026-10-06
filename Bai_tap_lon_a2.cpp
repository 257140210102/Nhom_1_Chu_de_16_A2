#include<bits/stdc++.h>
using namespace std;

class MonHoc{
	private:
		string Ma_Mon; // ma mon hoc
		string Ten_Mon; // ten mon hoc
		int So_Tin; // so tin chi
		string Ngay_Thi; // ngay thi
		int Ca_Thi; // ca thi
		string Phong_Thi; // phong thi
		int So_Sinh_Vien; // so luong sinh vien dang ky
	public:
		MonHoc() { // ham tao
			Ma_Mon = "";
			Ten_Mon = "";
			So_Tin = 0;
			Ngay_Thi = "";
			Ca_Thi = 0;
			Phong_Thi = "";
			So_Sinh_Vien = 0;
		}; //ham sao chep
	    MonHoc(const MonHoc &mh) {
	        Ma_Mon = mh.Ma_Mon;
			Ten_Mon = mh.Ten_Mon;
			So_Tin = mh.So_Tin;
			Ngay_Thi = mh.Ngay_Thi;
			Ca_Thi = mh.Ca_Thi;
			Phong_Thi = mh.Phong_Thi;
			So_Sinh_Vien = mh.So_Sinh_Vien;
	    }
	    ~MonHoc(){ //ham huy
	    };
		void nhap(); // phuong thuc nhap
		void xuat() const; // phuong thuc xuat
		friend void nhap_ds(MonHoc ds[], int &n); // ham ban nhap danh sach
        friend void xuat_ds(const MonHoc ds[], int n); //ham ban in danh sach
        friend int so_sanh_theo_ngay(const MonHoc &a, const MonHoc &b); // so sanh theo ngay
        friend void sap_xep(MonHoc ds[], int n); // ham ban sap xep
        friend void tim_ten_mon(const MonHoc ds[], int n, string ten_mon); // ham ban tim theo ten mon
        friend void tim_ma_mon(const MonHoc ds[], int n, string ma_mon); // ham ban tim theo ma mon
        friend void bo_sung(MonHoc ds[], int &n, int vi_tri,const MonHoc &a); // ham bo sung
        friend void xoa(MonHoc ds[], int &n, int vi_tri);// ham xoa
};
// Ham nhap xuat danh sach mon hoc

// sap xep danh sach mon hoc theo ngay thi

// tim kiem mon hoc

// bo sung va xoa mon hoc

// Ham main de chay chuong trinh
int main(){
	MonHoc ds[200];
	int n;
	nhap_ds(ds,n);
	while(true){ // vong lap vo han de hien thi menu chuc nang
        cout<<"\n-------------LUA CHON YEU CAU-------------\n";
		cout << "1. Xuat danh sach mon hoc" << endl;
		cout << "2. Sap xep danh sach theo ngay thi" << endl;
		cout << "3. Tim mon hoc theo ten" << endl;
		cout << "4. Tim mon hoc theo ma" << endl;
		cout << "5. Bo sung mon hoc vao danh sach" << endl;
		cout << "6. Xoa mon hoc khoi danh sach" << endl;
		cout << "0. Thoat" << endl;
		int choice; // khai bao bien choice de luu lua chon cua nguoi dung
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice){
			case 1: // xuat danh sach mon hoc
				xuat_ds(ds,n);
				break;
			case 2: // sap xep danh sach mon hoc theo ngay thi
				sap_xep(ds,n);
				break;
			case 3:{ // tim mon hoc theo ten
			    string ten_mon;
                cout << "Nhap ten mon hoc can tim: ";
                cin.ignore();
                getline(cin, ten_mon);
				tim_ten_mon(ds, n, ten_mon);
				break;
				}
			case 4:{ // tim mon hoc theo ma
			    string ma_mon;
                cout << "Nhap ma mon hoc can tim: ";
                cin.ignore();
                cin>>ma_mon;
				tim_ma_mon(ds,n, ma_mon);
				break;
				}
			case 5:{ // bo sung mon hoc vao danh sach
				int vi_tri;
				cout << "Nhap vi tri can bo sung: ";
				cin >> vi_tri;
				MonHoc a;
				a.nhap();
				bo_sung(ds, n, vi_tri, a);
				break;
			}
			case 6:{ // xoa mon hoc khoi danh sach
				int vi_tri;
				cout << "Nhap vi tri can xoa: ";
				cin >> vi_tri;
				xoa(ds, n, vi_tri);
				break;
			}
			case 0: // thoat chuong trinh
				return 0;
			default: // neu nguoi dung nhap sai lua chon thi in ra thong bao
				cout << "Lua chon khong hop le!" << endl;
		}
	}
	return 0;
}
