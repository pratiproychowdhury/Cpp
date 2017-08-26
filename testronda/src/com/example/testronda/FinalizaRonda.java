package com.example.testronda;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.TextView;

public class FinalizaRonda extends Activity {

	TextView tv;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_finaliza_ronda);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.finaliza_ronda, menu);
		return true;
	}
	
	public void descarregarRotaFeita(View view) {

		
		 tv = (TextView) findViewById(R.id.resultado_ronda);
        //String yyy = getInputStreamFromUrl("http://multidot.com.br/mr/mr.php");
        //new RetreiveFeedTask().execute("http://multidot.com.br/mr/mr.php");
        tv.setText( "Esperando resposta do servidor" );
        //setContentView(tv);
        				
		new AsyncEnviaDadosRonda().execute("http://multidot.com.br/mr/mr.php", tv);
	}
	
	public static String getInputStreamFromUrl(String url) {
		  String content = null;
		  try {
		    HttpClient httpclient = new DefaultHttpClient();
		    HttpResponse response = httpclient.execute(new HttpGet(url));
		    HttpEntity entity = response.getEntity();
		    content = EntityUtils.toString(entity);
		  } catch (Exception e) {
			  content = "[GET REQUEST] Network exception " + e;
		  }
		  return content;
	}
}
