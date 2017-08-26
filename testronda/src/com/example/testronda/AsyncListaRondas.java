package com.example.testronda;

import java.net.URL;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;
import org.xml.sax.InputSource;
import org.xml.sax.XMLReader;

import android.os.AsyncTask;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.view.View;


public class AsyncListaRondas extends AsyncTask<Object, Void, String> {

    private Exception exception;
    ListView listaRondas;

    protected String doInBackground(Object... urls) {
    	
    	String content = null;
    	listaRondas = (ListView) urls[1];
    	
        try {
		    HttpClient httpclient = new DefaultHttpClient();
		    HttpResponse response = httpclient.execute(new HttpGet((String)urls[0]));
		    HttpEntity entity = response.getEntity();
		    content = EntityUtils.toString(entity);        	
        } catch (Exception e) {
        	content = "[GET REQUEST] Network exception " + e;
        }
        return content;
    }

    protected void onPostExecute(String feed) {

    	// Atualiza tela de quem chamou
    	// listaRondas. .setText( feed );
    }

 }

