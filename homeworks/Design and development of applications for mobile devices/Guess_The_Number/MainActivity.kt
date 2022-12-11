package com.example.guessthenumber

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.EditText

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun onClickForAddD(view: View) {
        val intent = Intent(this@MainActivity, GameActivity::class.java)
        val frst_num = findViewById<EditText>(R.id.firstNum)
        val scnd_num = findViewById<EditText>(R.id.secondNum)

        intent.putExtra("firstNum", frst_num.text)
        intent.putExtra("secondNum", scnd_num.text)
        startActivity(intent)
    }
}