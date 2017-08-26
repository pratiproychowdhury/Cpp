package com.example.testronda;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Vector;

import android.os.Parcelable;

import com.example.testronda.Ponto;

public class ListaPontos {

	Vector<Ponto> pontosRonda;
	List<Ponto> listaPontos;
	
	public ListaPontos() {
		
		pontosRonda = new Vector<Ponto>();
		listaPontos = Collections.synchronizedList(new ArrayList<Ponto>());
	}
	
	public Ponto retornaPonto() {
		
		// Apenas retorna o ponto, n�o o deleta da lista
		synchronized(ListaPontos.class) {
			if (listaPontos.isEmpty()) {
				return null;
			} else {
			return listaPontos.get(0);
			}
		}
	}
	
	public void InserePonto(Ponto pontoAtual) {
		
		// Colocar o hor�rio tamb�m...
		synchronized(ListaPontos.class) {
			listaPontos.add(pontoAtual);
		}
	}
	
	public void PontoEnviado() {
		
		// A transmiss�o do ponto deu certo
		synchronized(ListaPontos.class) {
			listaPontos.remove(0);
		}
	}
	
	public int tamanhoLista() {
		
		return listaPontos.size();
	}
}
