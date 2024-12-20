# Text-Editor
Kelompok Hamba Allah 
1. Edelweiss Salsabila - 103052300038
2. Muthia Rezi Aisyah - 103052300114
3. Amalia Ananda Putri - 103052330078

File FIX Program Text Editor yang dapat di run dengan benar: TextEditor.zip atau file TextEditor.

Proyek text editor ini dibuat dengan mengaplikasikan konsep struktur data yang telah dipelajari sebelumnya di mata kuliah ini, yaitu Singly Linked List dan Stack. Fitur-fitur yang dimuat dalam text editor ini antara lain, yaitu fitur memasukkan atau membuat kalimat baru, penyisipan kata (insert), penghapusan kata (delete), menampilkan teks (print), mencari kata (search), menghitung kata (word count), dan undo-redo.

Fitur-fitur yang digunakan, yaitu:
1. Pencarian Kata (Searching Word):
Pencarian kata dilakukan dengan melakukan perbandingan antara kata yang dicari dengan kata yang ada di dalam linked list. Perbandingan ini dilakukan sepanjang linked list dan berhenti ketika semua node sudah selesai dilakukan pengecekkan.
Contoh implementasi:
  - Setiap kata dalam linked list dibandingkan dengan kata yang dicari.
  - Jika ditemukan, maka lokasi kata ditampilkan dalam bentuk indeks kata dalam kalimat (posisi kata di dalam kalimat, dimana posisi kata dimulai dari indeks 1) dan variabel boolean found akan di set menjadi true.

2. Pengeditan Teks (Text Editing):
Fitur ini menggunakan Single Linked List (SLL) sebagai struktur datanya dengan fitur yang dikembangkan adalah penyisipan kata dan hapus kata. Untuk penyisipan kata, iterasi akan dimulai dari 0 agar dapat mengimplementasikan insert first (menyisipkan kata baru sebelum kata pertama), sedangkan saat delete, iterasi dimulai dari 1 atau node pada kata pertama.

3. Undo dan Redo
- Struktur data yang digunakan:
    - Stack
        - undoStack: Array dari List yang menyimpan salinan status teks sebelum terjadi perubahan.
        - redoStack: Array dari List yang menyimpan status teks saat undo dilakukan, memungkinkan untuk redo di masa yang akan mendatang selama tidak ada penambahan kata baru yang sebelum melakukan redo.
    
- Fungsi yang digunakan:
    - pushUndoState():
      Berfungsi untuk menyalin head ke dalam undoStack sebelum perubahan terjadi.
    - copyList():
      Membuat salinan terpisah dari head untuk disimpan di stack sehingga   perubahan pada head tidak memengaruhi stack.
    - clearList():
      Menghapus head saat undo/redo agar tidak ada data sisa yang tertinggal sebelum memulihkan kondisi dari stack.

4. Word Count:
Fitur ini memuat sebuah pointer dan counter. Pointer akan menunjuk ke node pertama dan counter akan bertambah satu (counter++) setiap kali pointer bergeser hingga ke node paling terakhir. Setelah itu, nilai counter akan dikembalikan sebagai hasil dari word count.

5. Display Text:
Fitur ini menggunakan pointer temp yang dimulai dari head linked list utama text editor untuk meng-outputkan isi kata dari node yang ditunjuk, lalu pointer akan bergeser dan terus melakukan hal yang sama (meng-output dan bergeser) hingga ke node paling terakhir dari linked list.

6. Input Kalimat:
Fitur ini memungkinkan untuk memasukan sebuah kalimat yang nantinya akan dipecah menjadi per kata menggunakan fungsi ss(string) dari kamus stringstream dan dimasukan ke dalam sebuah variabel yang nantinya akan dijadikan sebagai node baru dalam linked list agar memudahkan untuk fitur lainnya seperti penyisipan, penghapusan, hitung jumlah kata, dan pencarian kata.

Cara Menjalankan Program:
1. Run program di IDE C++.
2. Pilihan menu text editor:
- Menu 1 (Masukkan Kalimat)
  - Untuk menambah kalimat baru.
- Menu 2 (Sisipkan Kata)
  - Untuk menyisipkan kata di kalimat sesuai dengan posisi yang diinginkan (dimulai dari 0). Misal, jika ingin menambahkan di awal, maka kata akan ditambahkan di posisi 0.
Note: Hanya bisa menambahkan kata bukan kalimat.
- Menu 3 (Hapus Kata)
  - Untuk menghapus kata dalam kalimat. Posisi kata yang ingin dihapus dimulai dari 1. Jika ingin menghapus kata pertama di dalam kalimat, maka posisi kata yang dihapus adalah 1.
- Menu 4 (Tampilkan Teks)
  - Untuk menampilkan kalimat.
- Menu 5 (Cari Kata)
  - Untuk mencari kata di dalam kalimat. Ada kemungkinan kata yang dicari ditemukan lebih dari satu sehingga output-an nya nanti akan menghasilkan kata yang ingin dicari dengan posisi nya di dalam kalimat.
- Menu 6 (Total Kata)
  - Menghitung jumlah kata (bukan karakter) yang ada di dalam kalimat.
- Menu 7 (Undo)
  - Untuk melakukan undo.
- Menu 8 (Redo)
  - Untuk melakukan redo.
- Menu 9 (Keluar)
  - Keluar dari program text editor (bukan dari terminal).
