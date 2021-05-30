void print (Sach *&sach, int &n){
    cout <<"Nhap So Luong Sach: ";
    cin >> n;
    sach = new (Sach);
    for (int i = 0;i < n; i++){
    cout <<"Quyen Sach "<<i+1<<endl;
    print (sach+i);
    }
}
