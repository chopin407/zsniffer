// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//
//	ʹ��xml�ļ�ʵ��windows��ini�ļ��Ķ�д���á�
//

/**
 * Edited By Wubenqi, 2009-03-12
 * add 
	GetStrings
	GetInts
	GetBools
	�޸�ÿ�θ����Ժ�ˢ�������ļ�
 */

#ifndef BASE_XML_INI_FILE_H_
#define BASE_XML_INI_FILE_H_

#include <string>
#include <vector>

#include "base/markup_stl.h"

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

/**
 Windows Ini Examples File:
  [Showyz]
  Server=172.16.100.113
  [Sign]
  PfxFile=cert.pfx
  [Database]
  SignDBAddr=mysql://root:@localhost/eseal/
  StampDBAddr=Provider=SQLOLEDB;Server=210.74.41.61;Database=stamp_online;UserId=stamper;Password=stamperkba97013

  ��Ӧ�� XMLIni Examples File:
  <?xml version="1.0" encoding="gb2312"?>
  <XMLIni>
   <Section name="Showyz">
    <Item name="Server">172.16.100.113</Item>
   </Section >
   <Section name="Sign">
    <Item name="PfxFile">cert.pfx</Item>
   </Section >
   <Section name="Database">
    <Item name="SignDBAddr">mysql://root:@localhost/eseal/</Item>
    <Item name="Server" >StampDBAddr=Provider=SQLOLEDB;Server=210.74.41.61;Database=stamp_online;UserId=stamper;Password=stamperkba97013</Item>
   </Section>
  </XMLIni>
*/

/**
 * DESCRIPTION��
 *	������Ҫ����LoadXMLIniFile������Ȼ�����ʹ�ö�д�����ļ���Ϣ
 *	���Ҫ������������ҪƵ������XMLIniFile�ļ���������Ϊһ������ʹ�ã�
 *	����XMLIniFileԪ��ֵ(����Put����)�Ժ����õ��������ڴ�������Ҫ���������ļ�����Ҫ����Flush����
 */
class XMLIniFile {
public:
	XMLIniFile(void);
	virtual ~XMLIniFile(void);

public:
	/**
	 * DESCRIPTION��
	 *	װ��XMLIni�ļ�������ļ������ڻ�򿪳��� ����false,
	 *  �Ժ�Ĳ�����Ч
	 * return:
	 *  �ɹ�Ϊtrue�� ����Ϊfalse
	 */
	bool LoadXMLIniFile( const char* pstrFilename );
	
	/**
	 * DESCRIPTION��
	 *	���������Ϣֵ������char*
	 * param:
	 *  pstrSection��pstrKey��cchMax��pstrDefaultΪ���������pstrValueΪ�������
	 *  cchMaxΪ���ز���pstrValue�Ļ������ֵ���������������ȣ���ֻ����cchmax�Ĵ�С
	 *  ����ַ����Զ��ض�
	 *	���û���ҵ���ֵ���򷵻ص���Ĭ��ֵ��ʹ�õ�ʱ��ҪĬ��ֵ���Ȳ��ܳ���
	 *  ���뻺�����󳤶ȡ�
	 * return:
	 *  �ɹ�Ϊtrue�� ����������Ϊnull������Ϊfalse
	 */
	bool GetString( const char* pstrSection, const char* pstrKey, char* pstrValue,  unsigned int cchMax, const char* pstrDefault=NULL );
	
	/**
	 * DESCRIPTION��
	 *	���������Ϣֵ������string
	 * param:
	 *  pstrSection��pstrKey��pstrDefaultΪ���������sValueΪ�������
	 * return:
	 *  �ɹ�Ϊtrue�� ����������Ϊnull������Ϊfalse
	 */
	bool GetString( const char* pstrSection, const char* pstrKey, std::string& sValue, const char* pstrDefault=NULL );
	bool GetStrings( const char* pstrSection, const char* pstrKey, std::vector<std::string>& sValue );
	

	/**
	 * DESCRIPTION��
	 *	���������Ϣֵ������int, ���ֵ������int���ͣ����������iValueΪ0
	 * param:
	 *  pstrSection��pstrKey��iDefaultΪ���������iValueΪ�������
	 * return:
	 *  �ɹ�Ϊtrue�� ����������Ϊnull������Ϊfalse
	 */
	bool GetInt( const char* pstrSection, const char* pstrKey, int& iValue,  int iDefault=0 );
	bool GetInts( const char* pstrSection, const char* pstrKey, std::vector<int>& iValue );

	/**
	 * DESCRIPTION��
	 *	���������Ϣֵ������bool
	 *	xml�ļ����ֵ�ĵ�һ���ַ�ֵΪ t/T/y/Y/1,����true��Ϊf/F/n/N/0������false 
	 *	�����ǣ�����Ĭ��ֵ
	 * param:
	 *  pstrSection��pstrKey��bDefaultΪ���������bValueΪ�������
	 * return:
	 *  �ɹ�Ϊtrue�� ����������Ϊnull������Ϊfalse
	 */
	bool GetBool( const char* pstrSection, const char* pstrKey, bool& bValue, bool bDefault=true );
	bool GetBools( const char* pstrSection, const char* pstrKey, std::vector<bool>& bValue );
	
	/**
	 * DESCRIPTION��
	 *	���������Ϣֵ,����XMLIni�ļ�����ң��ҵ�����ΪpstrValue
	 *	�Ҳ����������һ��pstrSection��pstrKey��pstrValue
	 * param:
	 *  pstrSection��pstrKey��pstrValueΪ�������
	 * return:
	 *  �ɹ�Ϊtrue�� ����������Ϊnull������Ϊfalse
	 */
	bool PutString( const char* pstrSection, const char* pstrKey, const char* pstrValue );

	/**
	 * DESCRIPTION��
	 *	���������Ϣֵ������XMLIni�ļ�����ң��ҵ����£���������һ��
	 * param:
	 *  pstrSection��pstrKey��iValueΪ�������
	 * return:
	 *  �ɹ�����true�� ����������Ϊnull������Ϊfalse
	 */
	bool PutInt( const char* pstrSection, const char* pstrKey, int iValue );

	/**
	 * DESCRIPTION��
	 *	���������Ϣֵ, ����XMLIni�ļ�����ң��ҵ����£���������һ��
	 *	�������bValue�ں���XMLIni�ļ���Ĵ洢��ֵ��bValueΪtrue����"true", Ϊfalse, ��"false"
	 * param:
	 *  pstrSection��pstrKey��bValueΪ�������
	 * return:
	 *  �ɹ�����true�� ����������Ϊnull������Ϊfalse
	 */
	bool PutBool( const char* pstrSection, const char* pstrKey, bool bValue );

	/**
	 * DESCRIPTION��
	 *	ɾ��������ϢֵԪ�ء�
	 * param:
	 *  pstrSection��pstrKey
	 * return:
	 *  �޷���ֵ
	 */
	void DeleteKey( const char* pstrSection, const char* pstrKey );
	
	/**
	 * DESCRIPTION��
	 *	ɾ��������Ϣ�ڵ㡣
	 * param:
	 *  pstrSection
	 * return:
	 *  �޷���ֵ
	 */
	void DeleteSection( const char* pstrSection );
	
	/**
	 * DESCRIPTION��
	 *	�������Ĳ������浽�ļ��
	 * param:
	 *  ��
	 * return:
	 *  �޷���ֵ
	 */	
	void Flush(void);

private:
	/**
	 * DESCRIPTION��
	 *	����������Ϣ
	 * param:
	 *  ����: szSection��strItem��strValue
	 *	���: ��
	 * return:
	 *  �޷���ֵ
	 */	
	void SetEntry ( const std::string& strSection, const std::string& strItem, const std::string& strValue );
	
	/**
	 * DESCRIPTION��
	 *	�õ�������Ϣ
	 * param:
	 *  ����: szSection��strItem
	 *	���: strValue
	 * return:
	 *  �޷���ֵ
	 */	
  bool FindEntry( const std::string& strSection, const std::string& strItem, std::string& strValue );
  bool FindEntrys( const std::string& strSection, const std::string& strItem, std::vector<std::string>& strValues );
  bool FindEntrys( const std::string& strSection, const std::string& strItem, std::vector<int>& iValues );

  CMarkupSTL	xml_ini_parser_;				  //xml�ļ�������
  bool			inited_;					      //��ʼ����־������ļ��򿪳���Ϊfalse,����Ϊtrue, ֵΪfalse��������������ʧЧ
  char			ini_file_name_[MAX_PATH];	//�����ļ���������Ҫ�õ���
  bool			updated_;
};

#endif //endif BASE_XML_INI_FILE_H_
