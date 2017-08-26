package com.example.testronda;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Ponto {

	public String horario;
	public Double latitude;
	public Double longitude;
	
	public Ponto(Double lat, Double lon) {
		
		latitude = lat;
		longitude = lon;
		// horario = System.currentTimeMillis();
		// horario = new SimpleDateFormat("yyyyMMddHHmmssSS").format(new Date());
		//horario = DateFormat.getDateInstance().format("yyyyMMddHHmmssSS").toString();
	}
}
