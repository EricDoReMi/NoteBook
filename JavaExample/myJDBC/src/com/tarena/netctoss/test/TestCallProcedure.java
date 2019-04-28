package com.tarena.netctoss.test;

import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.Types;

import com.tarena.netctoss.utils.DBUtils;

public class TestCallProcedure {
	public static void main(String[] args) throws Exception {
		// 用JDBC调用存储过程
		Connection con = DBUtils.getConnection();
		// 创建可调用Statement
		CallableStatement ctmt = 
			con.prepareCall("call helloworld(?,?,?,?)");

		// 设置输入参数(in)
		ctmt.setInt(1, 200);
		ctmt.setInt(2, 50);

		// 注册输出参数(out)
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
