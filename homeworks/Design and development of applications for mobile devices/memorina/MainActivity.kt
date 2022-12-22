package com.example.cardgame

import android.app.ActionBar
import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.AttributeSet
import android.util.Log
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.Toast
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch

class MainActivity : AppCompatActivity() {
    var firstCard: View = View(this)
    var openCardsCount = 0
    var allCount = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val layout = LinearLayout(applicationContext)
        layout.orientation = LinearLayout.VERTICAL

        val params = LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT,
            LinearLayout.LayoutParams.MATCH_PARENT)
        params.weight = 1.toFloat()

        val pnt = arrayOf(R.drawable.apple,
            R.drawable.bear,
            R.drawable.fox,
            R.drawable.frog,
            R.drawable.hedgehog,
            R.drawable.pig,
            R.drawable.squarecat)

        val catViews = ArrayList<ImageView>()
        pnt.shuffle()

        val colorListener = View.OnClickListener() {
            when (openCardsCount) {
                0 -> {
                    firstCard = it; openCardsCount++;
                    GlobalScope.launch(Dispatchers.Main) {
                        flipCard(firstCard as ImageView, pnt[it.tag.toString().toInt()])
                    }
                }
                1 -> {
                    if (it.tag == firstCard.tag) {
                        GlobalScope.launch(Dispatchers.Main) {
                            openCardsCount++;
                            flipCard(firstCard as ImageView, pnt[it.tag.toString().toInt()])
                            delay(1000)
                            hideCard(it as ImageView)
                            hideCard(firstCard as ImageView)
                            openCardsCount = 0
                            allCount += 1

                            if (allCount == pnt.size) { // всплывающее окно
                                val txt = "You're win"
                                val dur = Toast.LENGTH_SHORT
                                val toast = Toast.makeText(applicationContext, txt, dur)
                                toast.show()
                            }
                        }
                    } else {
                        GlobalScope.launch(Dispatchers.Main) {
                            openCardsCount++;
                            flipCard(firstCard as ImageView, pnt[it.tag.toString().toInt()])
                            delay(1000)
                            flipCard(firstCard as ImageView, R.drawable.squarecat)
                            flipCard(it as ImageView, R.drawable.squarecat)
                            openCardsCount = 0
                        }
                    }
                }
                else -> Log.d("mytag", "two cards are open already")
            }
        }

        for (i in 1..16) {
            catViews.add( // вызываем конструктор для создания нового ImageView
                ImageView(applicationContext).apply {
                    setImageResource(R.drawable.squarecat)
                    layoutParams = params
                    tag = (i - 1) / 2 // TODO: указать тег в зависимости от картинки
                    setOnClickListener(colorListener)
                })
        }

        catViews.shuffle()

        val rows = Array(4, { LinearLayout(applicationContext)})
        var count = 0

        for (view in catViews) {
            val row: Int = count / 4
            rows[row].addView(view)
            count ++
        }

        for (row in rows) {
            row.apply{
                orientation = LinearLayout.HORIZONTAL
                layoutParams = params
            }
            layout.addView(row)
        }

        val cat = ImageView(applicationContext)
        cat.setImageResource(R.drawable.squarecat); cat.layoutParams = params
        val cat2 = ImageView(applicationContext)
        cat2.setImageResource(R.drawable.squarecat); cat2.layoutParams = params
        val cat3 = ImageView(applicationContext)
        cat3.setImageResource(R.drawable.squarecat)
        val cat4 = ImageView(applicationContext)
        //cat.layoutParams = ViewGroup.LayoutParams(applicationContext, )
        cat4.setImageResource(R.drawable.squarecat)
        val row1 = LinearLayout(applicationContext)
        row1.orientation = LinearLayout.HORIZONTAL
        row1.setBackgroundColor(Color.GRAY)
        row1.addView(cat2); row1.addView(cat);
        val row2 = LinearLayout(applicationContext)
        row2.orientation = LinearLayout.HORIZONTAL
        row2.setBackgroundColor(Color.GRAY)
        row2.addView(cat3); row2.addView(cat4);
        layout.addView(row1); layout.addView(row2)

        setContentView(layout)
    }

    suspend fun setBackgroundWithDelay(v: View) {
        delay(1000)
        v.setBackgroundColor(Color.YELLOW)
        delay(1000)
        v.visibility = View.INVISIBLE
        v.isClickable = false
    }

    suspend fun flipCard(v: ImageView,r: Int) {
        v.setImageResource(r)
        v.isClickable = !v.isClickable
    }

    suspend fun hideCard(v: ImageView) {
        v.visibility = View.INVISIBLE
        v.isClickable = false
    }
}
