package com.example.films

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.TextView
import java.util.*

class MainActivity : AppCompatActivity() {
    lateinit var movies: Array<String>;
    var last_movie = emptyArray<Int>();

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        movies = resources.getStringArray(R.array.films)
        for (i in movies.indices) {
            last_movie += 0
        }
    }

    fun onClick(view: View) {
        val tv: TextView = findViewById(R.id.lists)
        for (i in movies.indices) {
            if (i == movies.size - 1) {
                tv.text = "Movies are over"
            }
            val rand = Random().nextInt(movies.size)
            if (last_movie[rand] == 0) {
                tv.text = movies[rand]
                last_movie[rand] = 1
                break
            }
        }
    }

    fun onClearClick(v: View) {
        val tv: TextView = findViewById(R.id.lists)
        for (i in movies.indices) {
            last_movie[i] = 0
        }
        tv.text = "Movies cleared"
    }
}