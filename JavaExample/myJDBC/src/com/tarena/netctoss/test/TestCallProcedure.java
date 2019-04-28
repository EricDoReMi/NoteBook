package com.tarena.netctoss.test;

import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.Types;

import com.tarena.netctoss.utils.DBUtils;

public class TestCallProcedure {
	public static void main(String[] args) throws Exception {
		// ��JDBC���ô洢����
		Connection con = DBUtils.getConnection();
		// �����ɵ���Statement
		CallableStatement ctmt = 
			con.prepareCall("call helloworld(?,?,?,?)");

		// �����������(in)
		ctmt.setInt(1, 200);
		ctmt.setInt(2, 50);

		// ע���������(out)
		ctmt.registerOutParameter(3, Types.INTEGER);
		ctmt.registerOutParameter(4, Types.INTEGER);

		ctmt.execute();

		int a = ctmt.getInt(3);
		int b = ctmt.getInt(4);
		System.out.println(a);
		System.out.println(b);

		con.close();

	}
}
