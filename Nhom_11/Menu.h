void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, BSTDungCu& root, BSTCustomer& root2);

void XuatMenu()
{
	cout << "================= HE THONG CHUC NANG =================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Nhap du lieu DO DUNG CU THE THAO tu file (Tao cay)";
	cout << "\n2.Xuat thong tin DO DUNG CU THE THAO";
	cout << "\n3.Nhap du lieu KHACH HANG tu file (Tao cay)";
	cout << "\n4.Xuat thong tin KHACH HANG\n";
	cout << "======================================================";
	cout << "\n5.Tim dung cu the thao khi biet ma dung cu";
	cout << "\n6.Chinh sua don gia cua dung cu";
	cout << "\n7.Xoa thong tin dung cu the thao voi ma dung cu";
	cout << "\n======================================================";
	cout << "\n8.Xuat hoa don khach hang mua hang";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\n Vui long chon menu [0 -> " << soMenu << "], stt= ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, BSTDungCu& root, BSTCustomer& root2)
{
	char* filename;
	int kq, dongia;
	KeyType x, maDC;
	BSTDungCu p;
	char tenDC[30];
	int soLuong;
	BSTDungCu foundNode = NULL;
	switch (menu)
	{
	case 1:
		cout << "\n1.Nhap du lieu do dung cu the thao tu file (Tao cay) ";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = FileBST_DCu(root, filename);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao cay BST thanh cong";
		cout << endl;
		delete[]filename;
		break;
	case 2:
		cout << "\n2.cay BST hien hanh, xuat theo thu tu truoc(NLR): \n";
		TieuDe();
		PreOrder(root);
		KeNgang();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR): \n";
		TieuDe();
		InOrder(root);
		KeNgang();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN): \n";
		TieuDe();
		PosOrder(root);
		KeNgang();
		cout << endl;
		break;
	case 3:
		cout << "\n3.Nhap du lieu KHACH HANG tu file (Tao cay)";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = FileBST_KH(root2, filename);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao cay BST thanh cong";
		cout << endl;
		delete[]filename;
		break;
	case 4:
		cout << "\n4.Xuat thong tin KHACH HANG\n";
		cout << "\ncay BST hien hanh, xuat theo thu tu truoc(NLR): \n";
		TieuDe_KH();
		PreOrder_KH(root2);
		KeNgang2();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR): \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang2();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN): \n";
		TieuDe_KH();
		PosOrder_KH(root2);
		KeNgang2();
		cout << endl;
		break;
	case 5:
		cout << "\n3.Tim dung cu the thao khi biet ma dung cu";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe();
		InOrder(root);
		KeNgang();

		cout << "\nNhap ma dung cu the thao \nmaNV="; cin >> x;
		p = Search(root, x);
		if (p == NULL)
			cout << "\nKhong tim thay thong tin dung cu the thao co ma" << x;
		else
		{
			cout << "\nThong tin dung cu the thao co ma" << x << ":\n";
			TieuDe();
			Xuat_NV(p->info);
			KeNgang();
		}
		break;
	case 6:
		cout << "\n4.Chinh sua don gia cua dung cu";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe();
		InOrder(root);
		KeNgang();

		cout << "\nNhap ma dung cu can tim:\nmaDC= ";
		cin >> x;
		p = Search(root, x);
		if (p == NULL)
			cout << "\nKhong tim thay thong tin dung cu the thao co ma" << x;
		else
		{
			cout << "\nThong tin dung cu co ma " << x << " :\n";
			TieuDe();
			Xuat_NV(p->info);
			KeNgang();

			cout << "\n\nNhap DON GIA MOI cua dung cu, dongia = ";
			cin >> dongia;
			p->info.donGia = dongia;
			cout << "\nThong tin nhan vien co ma " << x << " :\n";
			TieuDe();
			Xuat_NV(p->info);
			KeNgang();
		}
		cout << endl;
		break;
	case 7:
		cout << "\n5.Xoa thong tin dung cu the thao voi ma dung cu";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe();
		InOrder(root);
		KeNgang();
		if (root == NULL)
			cout << "\nBST rong!";
		else
		{
			cout << "\n\nNhap ma dung cu can xoa : "; cin >> maDC;
			kq = DeleteNode(root, maDC);
			if (kq)
			{
				cout << "\nDa xoa thanh cong";
				cout << "\nDanh sach moi theo thu tu dau (NLR):\n\n";
				TieuDe();
				PreOrder(root);
				KeNgang();
			}
			else cout << "\nKhong tim thay ma dung cu co ma la " << maDC;
		}
		break;
	case 8:
		cout << "\n8. Xuat hoa don khach hang mua hang";
		int soHoaDon;
		cout << "\nDanh sach dung cu";
		TieuDe();
		InOrder(root);
		KeNgang();
		cout << "\nDanh sach khach hang";
		TieuDe_KH();
		PreOrder_KH(root2);
		KeNgang2();
		cout << "\nNhap so hoa don: ";
		cin >> soHoaDon;
		XuLyHT(root2, root, soHoaDon);
		break;

	case 0:
		cout << "\n0. Thoat chuong trinh!\n";
		exit(0);
		break;

	default:
		cout << "\nLua chon khong hop le!\n";
		break;
	}
	_getch();
}
