import tkinter
from tkinter  import *
import sqlite3

conn = sqlite3.connect('dblab.db')
c = conn.cursor()
c.execute("CREATE TABLE IF NOT EXISTS products (name TEXT PRIMARY KEY,available INTEGER, cost REAL,t_cost REAL)")
root =Tk()
root.geometry("400x200+200+100")
root.title("DB Task")


Tops = Frame(root, width=300 , height =100)
Tops.pack(side = TOP)

f1 = Frame(root, width=300 ,height = 200)
f1.pack(side = LEFT )

f2 = Frame(root, width=200 ,height = 200)
f2.pack(side = RIGHT)

lbl = Label(Tops, font =('arial',30,'bold'), text ="DB Task",  bd =10 , anchor = 'w')
lbl.grid(row=0,column = 0)

lbl1 = Label(f1, font =('arial',10,'bold'), text ="Name",  bd =10 , anchor = 'w')
lbl1.grid(row=0,column = 0)
lbl2 = Label(f1, font =('arial',10,'bold'), text ="Available",  bd =10 , anchor = 'w')
lbl2.grid(row=1,column = 0)
lbl3 = Label(f1, font =('arial',10,'bold'), text ="Cost",  bd =10 , anchor = 'w')
lbl3.grid(row=2,column = 0)

txt1 = Entry(f1,font =('arial',10,'bold'))
txt1.grid(row=0, column = 1)

txt2 = Entry(f1,font =('arial',10,'bold'))
txt2.grid(row=1, column = 1)

txt3 = Entry(f1,font =('arial',10,'bold'))
txt3.grid(row=2, column = 1)
conn.commit()

def callback1():    
    try:
        c.execute("INSERT INTO products VALUES('"+txt1.get()+"',"+txt2.get()+","+txt3.get()+"," +txt2.get()+"*"+txt3.get()+")")
        conn.commit()
    except:
        print("INSERT INTO products VALUES('"+txt1.get()+"',"+txt2.get()+","+txt3.get()+"," +txt2.get()+"*"+txt3.get()+")")  
        print("Item already exists")

def callback2():    
    try:
        c.execute("UPDATE products SET available = "+txt2.get()+", cost = "+txt3.get()+", t_cost = " +txt2.get()+"*"+txt3.get()+" WHERE name = '"+txt1.get()+"'")
        conn.commit()
    except:
        print("UPDATE products SET available = "+txt2.get()+", cost = "+txt3.get()+", t_cost = " +txt2.get()+"*"+txt3.get()+" WHERE name = '"+txt1.get()+"'")
        print("Failed to update")

def callback3():    
    try:
        c.execute("DELETE FROM products WHERE name ='"+ txt1.get()+"'")
        conn.commit()
    except:
        print("DELETE FROM products WHERE name ='"+ txt1.get()+"'")  
        print("Failed to delete")

    
b1=Button(f2,command=callback1,text="Insert",width = 10).grid(row=0)
b2=Button(f2,command=callback2,text="Update",width = 10).grid(row=1)
b3=Button(f2,command=callback3,text="Delete",width = 10).grid(row=2)

    
root.mainloop()
c.close()
conn.close()
