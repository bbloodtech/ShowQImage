1. �����̻���QT5.5.1������ʹ��֮ǰ���Ȱ�װQT5.5.1�����ϰ汾��
   
2. �����̲������޸������IP��ʹ��֮ǰ����������ͻ�������޸������IP���������ڵ����Ρ�

3. Ŀ¼�ṹ����

   /ShowQImage
     �� Bin      �� ImageConvert.dll����ͼ���ʽת��
     ��
     �� Include  �� ͷ�ļ�
     ��   �� Media       : ת����ͷ�ļ�
     ��   �� GenICam     : SDK���ͷ�ļ������������SDK�汾���Դ���ͷ�ļ���(SDK��װĿ¼��\Development\Include��)
     ��   �� Infra       ��SDK���ͷ�ļ������������SDK�汾���Դ���ͷ�ļ���(SDK��װĿ¼��\Development\Include��)
     ��   �� Memory      ��SDK���ͷ�ļ������������SDK�汾���Դ���ͷ�ļ���(SDK��װĿ¼��\Development\Include��)
     ��
     �� Depends  ��  ����ʱ������
     ��   �� ImageConvert.lib:  ת���
     ��   �� MVSDKmd.lib     �� SDK�⡣���������SDK�汾���Դ��Ŀ��ļ���(SDK��װĿ¼��\Development\Lib��)
     ��
     �� Src
     ��   �� CammerWidget.h  �� �����
     ��   �� CammerWidget.cpp�� �����
     ��   �� cammerwidget.ui �� �����
     ��   �� main.cpp         
     ��   �� form.h          �� ������
     ��   �� form.cpp        �� ������
     ��   �� form.ui         �� ������
     ��   �� MessageQue.h    �� ֡����������ݽṹ
     ��
     �� ShowQImage.pro

4. ע�����

   (1) QtCreator�����̺���Ҫ�л���"��Ŀ"ҳ�棬�ֶ�ȥ����ѡShadow build�������Զ����ɵĹ���Ŀ¼���Ҳ��������ļ����������
   (2) Ŀǰ����ֻ֧��Mono8��RGB24ͼ������ת����QImage��Mono8����Ҫת�����ֱ������QImage�������ʽͨ��ImageConvert����ת����RGB24������QImage��
   (3) Sample��ͨ��QLabel��ʾͼ��QLabelֻ֧��QPixmap�������Ƚ�QImageת��ΪQPixmap��ת�������ͼ����ʾ�ӳ١�

                                                                             - END -