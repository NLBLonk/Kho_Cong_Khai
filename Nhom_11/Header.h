#define MAXCOT 61
typedef char KeyType[10];
typedef char KeyTypeKH[8];

struct dungcu
{
	KeyType maDC;
	char tenDC[30];
	int soLuong;
	int donGia;
};

struct BSNode
{
	dungcu info;
	BSNode* left;
	BSNode* right;
};

struct Ngay
{
	int ngay;
	int thang;
	int nam;
};

struct KhachHang
{
	KeyTypeKH maKH;
	char hoTen[20];
	char diaChi[30];
	char sdt[11];
	//Ngay ngayMua;
};
struct HoaDon
{
	char tenKH[20];  // Tên khách hàng
	struct SanPham
	{
		char tenDC[30]; // Tên dụng cụ
		int soLuong;    // Số lượng
		int donGia;     // Đơn giá
	} sanPham[100];     // Danh sách sản phẩm
	int soSP;           // Số lượng sản phẩm
	int tongTien;       // Tổng tiền hóa đơn
};


struct BSNodeKH
{
	KhachHang info;
	BSNodeKH* left;
	BSNodeKH* right;
};

//Cay nhi phan tim kiem
typedef BSNode* BSTDungCu;
typedef BSNodeKH* BSTCustomer;

//Khai bao nguyen mau
//***********************DUNG CU**************************
BSNode* CreateNode(dungcu x);
void CreateBST(BSTDungCu& root);
int InsertNode(BSTDungCu& root, dungcu x);
int FileBST_DCu(BSTDungCu& root, char* filename);
void TieuDe();
void KeNgang2();
void KeNgang();
void Xuat_NV(dungcu p);
//===============================
void PreOrder(BSTDungCu root);
void InOrder(BSTDungCu root);
void PosOrder(BSTDungCu root);
//===============================

//Tao nut voi x cho truoc
BSNode* CreateNode(dungcu x)
{
	BSNode* p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

//Khoi tao vao cay BST rong 
void CreateBST(BSTDungCu& root)
{
	root = NULL;
}

//Them x vao cay BST
int InsertNode(BSTDungCu& root, dungcu x)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maDC, x.maDC) == 0)

			return 0;
		if (strcmp(root->info.maDC, x.maDC) > 0)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}

//Tao cay BST tu file
int FileBST_DCu(BSTDungCu& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType maDC;
	char tenDC[30];
	int soLuong;
	int donGia;

	int kq;
	CreateBST(root);
	dungcu x;
	while (!in.eof())
	{
		in >> x.maDC; 
		in >> x.tenDC;
		in >> x.soLuong; 
		in >> x.donGia; 
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

//========================================================
//Xuat tieu de
void TieuDe()
{
	int i;
	cout << "\n";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";
	cout << endl;
	cout << setiosflags(ios::left);
	cout << ":"
		<< setw(8) << "MaDC"
		<< ":"
		<< setw(25) << "Ten dung cu"
		<< ":"
		<< setw(9) << "So luong"
		<< ":"
		<< setw(15) << "Don gia"
		<< ":";
	cout << "\n";
	for (i = 0; i < MAXCOT; i++)
		cout << "=";
	cout << ":";
}
void TieuDe_KH()
{

	int i;
	cout << "\n";
	for (i = 1; i <= 84; i++)
		cout << "=";
	cout << ":";
	cout << endl;
	cout << setiosflags(ios::left);
	cout << ":"
		<< setw(10) << "MaKH"
		<< ":"
		<< setw(25) << "Ho va ten"
		<< ":"
		<< setw(30) << "Dia Chi"
		<< ":"
		<< setw(15) << "SDT"
		<< ":";
	cout << "\n";
	for (i = 0; i < 84; i++)
		cout << "=";
	cout << ":";
}
void KeNgang2()
{
	cout << endl;
	for (int i = 1; i <= 84; i++)
		cout << "=";
	cout << ":";
}

void KeNgang()
{
	cout << endl;
	for (int i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";
}
//========================================================

//Xuat 1 nhan vien
void Xuat_NV(dungcu p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ":"
		<< setw(8) << p.maDC
		<< ":"
		<< setw(25) << p.tenDC
		<< ":"
		<< setw(9) << p.soLuong
		<< ":"
		<< setw(15) << p.donGia
		<< ":";
		//<< setw(12) << setprecision(0) << setiosflags(ios::fixed) << p.luong
		//<< ":";
}
//NLR 
void PreOrder(BSTDungCu root)
{
	if (root != NULL)
	{
		Xuat_NV(root->info);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//LNR
void InOrder(BSTDungCu root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_NV(root->info);
		InOrder(root->right);
	}
}
//LRN
void PosOrder(BSTDungCu root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_NV(root->info);
	}
}

//***********************************KHACH HANG************************************
BSNodeKH* CreateNodeKH(KhachHang kh)
{
	BSNodeKH* cus = new BSNodeKH;
	if (cus != NULL)
	{
		cus->info = kh;
		cus->left = NULL;
		cus->right = NULL;
	}
	return cus;
}

void CreateBST_KH(BSTCustomer& root2)
{
	root2 = NULL;
}

int InsertNode_KH(BSTCustomer& root2, KhachHang kh)
{
	if (root2 != NULL)
	{
		if (strcmp(root2->info.maKH, kh.maKH) == 0)

			return 0;
		if (strcmp(root2->info.maKH, kh.maKH) > 0)
			return InsertNode_KH(root2->left, kh);
		else
			return InsertNode_KH(root2->right, kh);
	}
	root2 = CreateNodeKH(kh);
	if (root2 == NULL)
		return -1;
	return 1;
}

int FileBST_KH(BSTCustomer& root2, char* filename2)
{
	ifstream in(filename2);
	if (!in)
		return 0;
	KeyTypeKH maKH;

	int kq;
	CreateBST_KH(root2);
	KhachHang x;

	while (!in.eof())
	{
		in >> x.maKH; 
		in >> x.hoTen;
		in >> x.diaChi; 
		in >> x.sdt; 
		kq = InsertNode_KH(root2, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

void Xuat_KH(KhachHang kh)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ":"
		<< setw(10) << kh.maKH
		<< ":"
		<< setw(25) << kh.hoTen
		<< ":"
		<< setw(30) << kh.diaChi
		<< ":"
		<< setw(15) << kh.sdt
		<< ":";
	//<< setw(12) << setprecision(0) << setiosflags(ios::fixed) << p.luong
	//<< ":";
}

void PreOrder_KH(BSTCustomer root2)
{
	if (root2 != NULL)
	{
		Xuat_KH(root2->info);
		PreOrder_KH(root2->left);
		PreOrder_KH(root2->right);
	}
}

void InOrder_KH(BSTCustomer root2)
{
	if (root2 != NULL)
	{
		InOrder_KH(root2->left);
		Xuat_KH(root2->info);
		InOrder_KH(root2->right);
	}
}

void PosOrder_KH(BSTCustomer root2)
{
	if (root2 != NULL)
	{
		PosOrder_KH(root2->left);
		PosOrder_KH(root2->right);
		Xuat_KH(root2->info);
	}
}






BSTCustomer SearchByName(BSTCustomer root, const char* tenKH)
{
	if (root != NULL)
	{
		if (strcmp(root->info.hoTen, tenKH) == 0)
			return root;
		BSTCustomer found = SearchByName(root->left, tenKH);
		if (found != NULL) return found;
		return SearchByName(root->right, tenKH);
	}
	return NULL;
}

BSTDungCu SearchByName(BSTDungCu root, const char* tenDC)
{
	if (root != NULL)
	{
		if (strcmp(root->info.tenDC, tenDC) == 0)
			return root;
		BSTDungCu found = SearchByName(root->left, tenDC);
		if (found != NULL) return found;
		return SearchByName(root->right, tenDC);
	}
	return NULL;
}






void XuLyHT(BSTCustomer rootKH, BSTDungCu rootDC, int soHoaDon)
{
	HoaDon dsHoaDon[100]; // Danh sách hóa đơn

	for (int i = 0; i < soHoaDon; i++)
	{
		cout << "\nNhap thong tin hoa don thu " << i + 1 << ":\n";

		// Nhập tên khách hàng
		cout << "Nhap ten khach hang: ";
		cin.ignore();
		cin.getline(dsHoaDon[i].tenKH, 20);

		// Tìm khách hàng trong BST
		BSTCustomer khNode = SearchByName(rootKH, dsHoaDon[i].tenKH);
		if (khNode == NULL)
		{
			cout << "Khong tim thay khach hang voi ten: " << dsHoaDon[i].tenKH << ". Hoa don se duoc tao voi thong tin da nhap.\n";
		}

		// Nhập số dụng cụ khách hàng mua
		cout << "Nhap so dung cu mua: ";
		cin >> dsHoaDon[i].soSP;

		dsHoaDon[i].tongTien = 0; // Khởi tạo tổng tiền hóa đơn

		for (int j = 0; j < dsHoaDon[i].soSP; j++)
		{
			cout << "\nNhap thong tin san pham thu " << j + 1 << ":\n";

			// Nhập tên dụng cụ
			cout << "Nhap ten dung cu: ";
			cin.ignore();
			cin.getline(dsHoaDon[i].sanPham[j].tenDC, 30);

			// Tìm dụng cụ trong BST
			BSTDungCu dcNode = SearchByName(rootDC, dsHoaDon[i].sanPham[j].tenDC);
			if (dcNode == NULL)
			{
				cout << "Khong tim thay dung cu voi ten: " << dsHoaDon[i].sanPham[j].tenDC << ". Bo qua san pham nay.\n";
				dsHoaDon[i].sanPham[j].soLuong = 0;
				dsHoaDon[i].sanPham[j].donGia = 0;
				continue;
			}

			// Nhập số lượng
			cout << "Nhap so luong: ";
			cin >> dsHoaDon[i].sanPham[j].soLuong;

			dsHoaDon[i].sanPham[j].donGia = dcNode->info.donGia;

			// Tính tổng tiền sản phẩm
			int thanhTien = dsHoaDon[i].sanPham[j].soLuong * dsHoaDon[i].sanPham[j].donGia;
			dsHoaDon[i].tongTien += thanhTien;
		}
	}

	// Xuất hóa đơn
	for (int i = 0; i < soHoaDon; i++)
	{
		cout << "\n===============================================";
		cout << "\nHoa don thu " << i + 1 << ":\n";
		cout << "Ten khach hang: " << dsHoaDon[i].tenKH << "\n";
		BSTCustomer khNode = SearchByName(rootKH, dsHoaDon[i].tenKH);
		if (khNode != NULL)
		{
			cout << "Dia chi: " << khNode->info.diaChi << "\n";
			cout << "So dien thoai: " << khNode->info.sdt << "\n";
		}
		else
		{
			cout << "Dia chi: Khong co thong tin\n";
			cout << "So dien thoai: Khong co thong tin\n";
		}
		cout << "\nTen dung cu                 So luong              Gia tien";
		cout << "\n-------------------------------------------------------------";

		for (int j = 0; j < dsHoaDon[i].soSP; j++)
		{
			cout << "\n"
				<< setw(25) << left << dsHoaDon[i].sanPham[j].tenDC
				<< setw(20) << left << dsHoaDon[i].sanPham[j].soLuong
				<< setw(20) << left << dsHoaDon[i].sanPham[j].soLuong * dsHoaDon[i].sanPham[j].donGia;
		}
		cout << "\n-------------------------------------------------------------";
		cout << "\nTong tien: " << dsHoaDon[i].tongTien;
		cout << "\n===============================================\n";
	}
}

//========================================================================