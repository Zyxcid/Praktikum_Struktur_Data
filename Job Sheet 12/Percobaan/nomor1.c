#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
using namespace std;

struct tree_node
{
    tree_node *left;
    tree_node *right;
    string nomor;
    string nama;
    string nim;
    string email;
};

tree_node *root;

bool isEmpty()
{
    return root == NULL;
}

void insert(string no, string nm, string n, string ml)
{
    tree_node *t = new tree_node;
    tree_node *parent;
    t->nomor = no;
    t->nama = nm;
    t->nim = n;
    t->email = ml;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    if (isEmpty())
        root = t;
    else
    {
        tree_node *curr;
        curr = root;

        while (curr != NULL)
        {
            parent = curr;
            if (t->nomor > curr->nomor)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        if (t->nomor < parent->nomor)
        {
            parent->left = t;
        }
        else
        {
            parent->right = t;
        }
    }
}

void inorder(tree_node *p)
{
    if (p != NULL)
    {
        if (p->left)
            inorder(p->left);
        cout << " | " << setw(10) << left << p->nomor << " | "
             << setw(20) << left << p->nama << " | "
             << setw(15) << left << p->nim << " | "
             << setw(25) << left << p->email << " |" << endl;
        if (p->right)
            inorder(p->right);
    }
}

void postorder(tree_node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << " | " << setw(10) << left << p->nomor << " | "
             << setw(20) << left << p->nama << " | "
             << setw(15) << left << p->nim << " | "
             << setw(25) << left << p->email << " |" << endl;
    }
}

void preorder(tree_node *p)
{
    if (p != NULL)
    {
        cout << " | " << setw(10) << left << p->nomor << " | "
             << setw(20) << left << p->nama << " | "
             << setw(15) << left << p->nim << " | "
             << setw(25) << left << p->email << " |" << endl;
        if (p->left)
            preorder(p->left);
        if (p->right)
            preorder(p->right);
    }
}

void print_preorder()
{
    preorder(root);
}
void print_postorder()
{
    postorder(root);
}

void print_inorder()
{
    inorder(root);
}

int main()
{
    root = NULL;
    string x, tmp, t, o;
    int ch;

    while (1)
    {
        system("cls");
        cout << "----------------------------------" << endl;
        cout << "| Menu Utama Operasi Pohon Biner |" << endl;
        cout << "----------------------------------" << endl;
        cout << "| 1 | Insert/Tambah Data         |" << endl;
        cout << "| 2 | Kunjungan In-Order         |" << endl;
        cout << "| 3 | Kunjungan Pre-Order        |" << endl;
        cout << "| 4 | Kunjungan Post-Order       |" << endl;
        cout << "| 5 | Exit                       |" << endl;
        cout << "----------------------------------" << endl;

        cout << "~~> Pilihan Anda : ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            cout << "> NOMOR : ";
            cin >> x;
            cout << "> Nama  : ";
            cin >> tmp;
            cout << "> NIM   : ";
            cin >> t;
            cout << "> Email : ";
            cin >> o;
            insert(x, tmp, t, o);

            cout << endl
                 << "[ DATA DIMASUKKAN ]";
            getch();
            fflush(stdin);
            break;
        case 2:
            cout << endl;
            cout << "----------------------" << endl;
            cout << "| Kunjungan In-Order |" << endl;
            cout << "----------------------" << endl;
            cout << " -----------------------------------------------------------------------------" << endl;
            cout << " | " << setw(10) << left << "No" << " | "
                 << setw(20) << left << "NAMA" << " | "
                 << setw(15) << left << "NIM" << " | "
                 << setw(25) << left << "EMAIL" << " |" << endl;
            cout << " -----------------------------------------------------------------------------" << endl;
            print_inorder();
            getch();
            break;
        case 3:
            cout << "-----------------------" << endl;
            cout << "| Kunjungan Pre-Order |" << endl;
            cout << "-----------------------" << endl;
            cout << " -----------------------------------------------------------------------------" << endl;
            cout << " | " << setw(10) << left << "No" << " | "
                 << setw(20) << left << "NAMA" << " | "
                 << setw(15) << left << "NIM" << " | "
                 << setw(25) << left << "EMAIL" << " |" << endl;
            cout << " -----------------------------------------------------------------------------" << endl;
            print_preorder();
            getch();
            break;
        case 4:
            cout << "------------------------" << endl;
            cout << "| Kunjungan Post-Order |" << endl;
            cout << "------------------------" << endl;
            cout << " -----------------------------------------------------------------------------" << endl;
            cout << " | " << setw(10) << left << "No" << " | "
                 << setw(20) << left << "NAMA" << " | "
                 << setw(15) << left << "NIM" << " | "
                 << setw(25) << left << "EMAIL" << " |" << endl;
            cout << " -----------------------------------------------------------------------------" << endl;
            print_postorder();
            getch();
            break;
        case 5:
            return 0;
        default:
            cout << "Pilihan yang Anda Masukkan salah!" << endl;
            getch();
            break;
        }
    }
}