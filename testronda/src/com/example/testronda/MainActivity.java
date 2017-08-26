package com.example.testronda;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.StrictMode;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

	public final static String EXTRA_USERNAME = "com.example.testronda.USERNAME";
	public final static String EXTRA_PASSWORD = "com.example.testronda.PASSWORD";
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
        TextView  tv = new TextView(this);
        CharSequence zzz = "MultiRonda";
        
        // workaround
        //StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        //StrictMode.setThreadPolicy(policy); 
        
        //String yyy = getInputStreamFromUrl("http://multidot.com.br/mr/mr.php");
        //tv.setText( yyy );
        //setContentView(tv);		
		setContentView(R.layout.activity_main);
        
        // final network code
		// new RetreiveFeedTask().execute("http://multidot.com.br/mr/mr.php");
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
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
	
	/** Called when the user clicks the Login button */
	public void sendLogin(View view) {
	    // Do something in response to login
		Intent intent = new Intent(this, EscolhaRonda.class);
		
		EditText editText = (EditText) findViewById(R.id.login_name);
		String username = editText.getText().toString();
		intent.putExtra(EXTRA_USERNAME, username);
		
		editText = (EditText) findViewById(R.id.login_password);
		String password = editText.getText().toString();
		intent.putExtra(EXTRA_PASSWORD, password);
		
	    startActivity(intent);
	}
}
