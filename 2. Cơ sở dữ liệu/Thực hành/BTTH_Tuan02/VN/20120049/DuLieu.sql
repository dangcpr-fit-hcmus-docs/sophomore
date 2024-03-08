USE [QLBanHang]
GO
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'000001', N'Nguyen Van A        ', N'Nam', N'0123456789', N'01A                           ')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'000002', N'Nguyen Van B        ', N'Nu ', N'0123456789', N'01B                           ')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'000003', N'Nguyen Van C        ', N'Nam', N'0123456789', N'01C                           ')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'000004', N'Nguyen Van D        ', N'Nu ', N'0123456789', N'01D                           ')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'000005', N'Nguyen Van E        ', N'Nam', N'0123456789', N'01E                           ')
GO
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'200001', CAST(N'2021-01-02' AS Date), N'000001')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'200002', CAST(N'2021-01-01' AS Date), N'000001')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'200003', CAST(N'2021-01-03' AS Date), N'000003')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'200004', CAST(N'2021-01-04' AS Date), N'000004')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'200005', CAST(N'2021-01-05' AS Date), N'000005')
GO
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'100001', N'Tuong ot                      ', CAST(N'2020-01-01' AS Date), CAST(25000 AS Numeric(8, 0)))
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'100002', N'Nuoc mam                      ', CAST(N'2020-01-02' AS Date), CAST(22500 AS Numeric(8, 0)))
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'100003', N'Ta giay                       ', CAST(N'2020-01-03' AS Date), CAST(132000 AS Numeric(8, 0)))
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'100004', N'Sua tuoi                      ', CAST(N'2020-01-04' AS Date), CAST(4000 AS Numeric(8, 0)))
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'100005', N'Dau an                        ', CAST(N'2020-01-05' AS Date), CAST(150000 AS Numeric(8, 0)))
GO
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'200001', N'100001', CAST(3 AS Numeric(2, 0)), CAST(75000 AS Numeric(8, 0)))
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'200002', N'100001', CAST(2 AS Numeric(2, 0)), CAST(50000 AS Numeric(8, 0)))
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'200003', N'100003', CAST(3 AS Numeric(2, 0)), CAST(396000 AS Numeric(8, 0)))
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'200004', N'100004', CAST(1 AS Numeric(2, 0)), CAST(4000 AS Numeric(8, 0)))
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'200005', N'100002', CAST(1 AS Numeric(2, 0)), CAST(22500 AS Numeric(8, 0)))
GO
