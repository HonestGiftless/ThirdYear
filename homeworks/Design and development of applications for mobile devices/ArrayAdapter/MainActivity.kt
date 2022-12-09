package com.example.people_list

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.ArrayAdapter
import android.widget.EditText
import android.widget.ListView
import kotlin.random.Random

class MainActivity : AppCompatActivity() {
    @SuppressLint("MissingInflatedId")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val lvPeople = findViewById<ListView>(R.id.people)
        val name = resources.getStringArray(R.array.name_list)
        val people = name.toMutableList()
        val suname = resources.getStringArray(R.array.secondname_list)
        val people_sec = suname.toMutableList()
        val rand = people_sec.random()

        val adapter = ArrayAdapter<String>(this, R.layout.item, people)
        lvPeople.adapter = adapter // задаем адаптер для отображения данных на списке
    }

    fun onAddPersonClick(view: View) {
        val name = resources.getStringArray(R.array.name_list)
        val people = name.toMutableList()
        val adapter = ArrayAdapter<String>(this, R.layout.item, people)
        val lvPeople = findViewById<ListView>(R.id.people)
        val suname = resources.getStringArray(R.array.secondname_list)
        val people_sec = suname.toMutableList()
        val rand = people_sec.random()
        val text = findViewById<EditText>(R.id.newname)
        if(!text.text.toString().isEmpty()) {
            adapter.add(text.text.toString() + ' ' + rand)
            text.setText("")
            adapter.notifyDataSetChanged()
        }
//        people.add(text.text.toString() + ' ' + rand)
        lvPeople.adapter = adapter
//        text.setText("")
        //TODO: реализовать добавление новых персон в список
        //имя считывать из текстового поля
        //Если нужно изменять число элементов, использовать Wut
    }

}

