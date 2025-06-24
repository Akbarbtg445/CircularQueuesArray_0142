/**
 *  @mainpage Documentation circular Queues
 * 
 * @section introduction
 * project ini merupakan struktur data
 * menggunbkan struktur data queues dengna pendekatan circular arrays.
 * 
 * @section Operations
 * project ini memiliki beberapa operasi antara lain:
 * 1.insert
 * 2.delete
 * 3.Display
 * 
 * @section cara penggunaan 
 * Berikut beberapa menu yang bisa digunakan :
 * 1.en queue
 * 2.de queue
 * 3.display
 * 4.exit
 * 
 * @author Profil
 * -nama :{M.Ridho Akbar}
 * -nim : {20240140142}
 * -kelas : {C}
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright {M.Ridho Akbar}@umy ac.id
 * */

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief  class ini untuk operasi lengkap queues
*/
class Queues {
    private:
    int FRONT ; /// <variable private front untuk menyimpan posisi depan antrian
    int REAR ; //< variable private rear untuk mentimpan posisi belakang antrian 
    int max = 5;///<variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5];///< variable private queue array untuk menyimpan eleman antrian 

    public:
    /**
     * @brief Construct a new queue object
     * set default queue null'
     * with front = -1 and rear = -1
     */
    Queues() 
    {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief method untuk memasukan data dalam antrian 
     * data dimasukan dalam variabel Queue_array
     */
    void insert ()
    {
        int num;////<variabel num untuk menyimpan nilai
        cout << "Enter a number :";
        cin >> num;
        cout << "endl";

        // 1.cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max-1) || (FRONT == REAR +1))
        {
            cout << "\nQueue overflow\n";
            return;
        }
        // 2.Cek apakah antrian kosong 
        if (FRONT == -1)
        {
            FRONT =0;
            REAR = 0;
        }
        else 
        {
            //jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
            REAR = 0;
            else 
            REAR = REAR +1;
        }
        queue_array[REAR] = num;
    }
    /**
     * @brief method untuk menghapus data dalam antrian 
     * data dihapuskan dari dalam variabel queue array
     */
    void remove ()
    {
        //cek apakah antrian kosong
        if (FRONT == -1 )
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\n The element deleted from the Queue is :" << queue_array[FRONT] << "\n";
        // cek apakah antrian adalam satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        } 
        else 
        {
            //jika elemen yang di hapus berada di posisi terakhir, kembali ke awal array
            if (FRONT == max -1)
            FRONT = 0;
            else
            FRONT = FRONT +1;
        }
    }
    /**
     * @brief method untuk menampilkan data dalam antrian
     * data di tampilkan yang berada dalam variabel queue array
     * */
    void display ()
    {
        int FRONT_position = FRONT ;///<variabel front_posisition untuk menandakan posisi elemen 
        int REAR_position = REAR ;//< variabel rear_posistion untuk menandakan posisi elemen 
        //cek apakah antrian kosong

        if (FRONT == -1)
        {
            cout << "Queue is empty \n";
            return;
        }
        cout << "\nElements in the queue are...\n";
        
        //jika front_position  <= REAR_position, literasi dari front hingga rear
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            while (FRONT_position<= max-1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            FRONT_position = 0;

            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};
/**
 * @brief method utama untuk menjalankan program 
 * 
 * @return int
 */
int main ()
{
    Queues q;///< objek untuk menggunakan member yang ada pada class queues
    char ch;///< variabel ch untuk menyimpan pilihan pada menu yang diberikan

    while (true)
    {
        try 
        {
            cout << "Menu" << endl;
            cout << "1. implement insert operation" << endl;
            cout << "2. impelement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit "<< endl;
            cout << "Enter your choiche (1-4):";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "invalid option!" << endl;
                    break;
                }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entred." << endl;
        }
    }
} ;