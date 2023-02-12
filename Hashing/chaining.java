package Hashing;

import java.util.ArrayList;
import java.util.LinkedList;

class chaining{
    int BUCKET;
    ArrayList<LinkedList<Integer>> table;

    chaining(int b){
        BUCKET = b;
        table = new ArrayList<LinkedList<Integer>>(b);
        for(int i=0;i<b;i++)
        table.add(new LinkedList<Integer>());
    }

    void insert(int key){
        int i = key%BUCKET;
        table.get(i).add(key);
    }
    void remove(int key){
        int i = key%BUCKET;
        table.get(i).remove((Integer)i);
    }

    boolean search(int key){
        int i = key%BUCKET;
        return table.get(i).contains(key);
    }
}
